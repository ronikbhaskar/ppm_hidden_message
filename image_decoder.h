/*
 * image_decoder.h
 * prototypes for steps to decode hidden message
 *
 * I don't really need a header file for this, but it's good for planning.
 * For this reason, I am writing this header file.
 *
 * Also, if I ever decide to take this further, 
 * I'll remember how to modify the work I did
 *
 * Author: Ronik
 */

#ifndef _IMAGE_DECODER_H
#define _IMAGE_DECODER_H

/* decode_ppm - decodes message  and prints to stdout
 *
 * ppm_path - file path to ppm for decoding
 * 
 * Returns: error code, 0 if success
 */
int decode_ppm(char *ppm_path);

#endif /* _IMAGE_DECODER_H */
