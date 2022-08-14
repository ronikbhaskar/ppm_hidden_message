/* hidden_message.c
 * 
 * see hidden_message.h for more details
 *
 * Author: Ronik 
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "hidden_message.h"

/* message_to_rgb - memory allocates unsigned char array to hold rgb message and fills array
 *
 * message - string to be converted to byte array
 * 
 * message_len - length of message
 * 
 * Returns: byte (bit) array of length message_len * 8
 */
uint8_t *message_to_rgb(char *message, int message_len)
{
    if (message_len <= 0)
    {
        fprintf(stderr, "message_to_rgb: message length must be positive\n");
        return NULL;
    }

    uint8_t *rgb_arr = (uint8_t*)malloc(sizeof(uint8_t) * message_len * 8);
    if (!rgb_arr)
    {
        fprintf(stderr, "message_to_rgb: unable to allocate rgb_arr\n");
        return NULL;
    }

    int i, j;
    for (i = 0; i < message_len; ++i)
    {
        /* read bits from largest place value to smallest (left to right) */
        for (j = 0; j < 8; ++j)
            rgb_arr[i * 8 + j] = message[i] >> (7 - j) & 0x1;
    }

    return rgb_arr;
}

/* print_ppm - prints the data of the ppm file to standard out
 * 
 * rgb - array of rgb values to print
 * 
 * rgb_len - length of array of rgb values to print
 * 
 * width - width of ppm image to print
 * 
 * height - height of ppm image to print
 * 
 * Returns: error code, 0 if successful
 */
int print_ppm(uint8_t *rgb, int rgb_len, int width, int height)
{
    if (width < 0 || height < 0 || width * height * 3 < rgb_len)
    {
        fprintf(stderr, "print_ppm: width or height is too small\n");
        return -1;
    }

    if (!rgb)
    {
        fprintf(stderr, "print_ppm: rgb is NULL ptr\n");
        return -1;
    }

    printf("P3\n%d %d\n255\n", width, height);

    int i, rgb_idx = 0, pixels = width * height;
    uint8_t r, g, b;

    for (i = 0; i < pixels; ++i)
    {
        r = rgb_idx < rgb_len ? rgb[rgb_idx++] : 0;
        g = rgb_idx < rgb_len ? rgb[rgb_idx++] : 0;
        b = rgb_idx < rgb_len ? rgb[rgb_idx++] : 0;
        printf("%d %d %d\n", r, g, b);
    }

    return 0;
}

int main(int argc, char **argv)
{

    int opt;
    char *message;
    int width = -1, height = -1;

    while((opt = getopt(argc, argv, ":m:w:h:")) != -1) 
    { 
        switch(opt) 
        { 
            case 'm':
                message = optarg; 
                break;
            case 'w':
                width = atoi(optarg);
                break;
            case 'h':
                height = atoi(optarg);
                break;
        } 
    } 

    /* unsafe, but what else should I do */
    int message_len = strlen(message);

    uint8_t *bit_array = message_to_rgb(message, message_len);

    print_ppm(bit_array, message_len * 8, width, height);

    free(bit_array);

    return 0;
}