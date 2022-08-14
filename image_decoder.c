/* image_decoder.c
 * 
 * see image_decoder.h for more details
 *
 * Author: Ronik 
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "image_decoder.h"

/* decode_ppm - decodes message  and prints to stdout
 *
 * ppm_path - file path to ppm for decoding
 * 
 * Returns: error code, 0 if success
 */
int decode_ppm(char *ppm_path)
{
    if (!ppm_path)
    {
        fprintf(stderr, "decode_ppm: NULL file path pointer\n");
        return -1;
    }

    FILE *fp;
    char buff[255];

    fp = fopen(ppm_path, "r");
    if (!fp)
    {
        fprintf(stderr, "decode_ppm: NULL file pointer\n");
        return -1;
    }

    int i, ret;
    for (i = 0; i < 4; ++i)
        ret = fscanf(fp, "%s", buff);

    i = 0;
    char current_char = 0;
    while ((ret = fscanf(fp, "%s", buff)) != -1)
    {
        switch (buff[0])
        {
            case '1':
                current_char = current_char | (1 << (7 - i++));
                break;
            case '0':
                current_char = current_char | (0 << (7 - i++));
                break;
            default:
                fprintf(stderr, "decode_ppm: improper encoding of file\n");
                break;
        }

        if (i == 8)
        {
            if (current_char == 0)
                break;
            
            printf("%c", current_char);
            i = 0;
            current_char = 0;
        }
    }

    printf("\n");

    fclose(fp);
    return 0;
}

int main(int argc, char **argv)
{
    int opt;
    char *path = NULL;

    while((opt = getopt(argc, argv, ":p:")) != -1) 
    { 
        switch(opt) 
        { 
            case 'p':
                path = optarg; 
                break;
        } 
    }
    
    decode_ppm(path);
    return 0;
}