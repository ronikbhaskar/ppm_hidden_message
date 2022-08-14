/*
 * hidden_message.h
 * prototypes for steps to produce hidden message
 *
 * I don't really need a header file for this, but it's good for planning.
 * For this reason, I am writing this header file.
 *
 * Also, if I ever decide to take this further, 
 * I'll remember how to modify the work I did
 *
 * Author: Ronik
 */

#ifndef _HIDDEN_MESSAGE_H
#define _HIDDEN_MESSAGE_H

typedef unsigned char uint8_t;

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
int print_ppm(uint8_t *rgb, int rgb_len, int width, int height);

/* message_to_rgb - memory allocates unsigned char array to hold rgb message and fills array
 *
 * message - string to be converted to byte array
 * 
 * message_len - length of message
 * 
 * Returns: byte (bit) array of length message_len * 8
 */
uint8_t *message_to_rgb(char *message, int message_len);

#endif /* _HIDDEN_MESSAGE_H */
