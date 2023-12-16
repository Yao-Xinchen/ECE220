/*									tab:8
 *
 * main.c - skeleton source file for ECE220 image processing MP6
 *
 * "Copyright (c) 2021 by Steven S. Lumetta
 *
 * Permission to use, copy, modify, and distribute this software and its
 * documentation for any purpose, without fee, and without written agreement is
 * hereby granted, provided that the above copyright notice and the following
 * two paragraphs appear in all copies of this software.
 * 
 * IN NO EVENT SHALL THE AUTHOR OR THE UNIVERSITY OF ILLINOIS BE LIABLE TO 
 * ANY PARTY FOR DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL 
 * DAMAGES ARISING OUT OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, 
 * EVEN IF THE AUTHOR AND/OR THE UNIVERSITY OF ILLINOIS HAS BEEN ADVISED 
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 * THE AUTHOR AND THE UNIVERSITY OF ILLINOIS SPECIFICALLY DISCLAIM ANY 
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF 
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  THE SOFTWARE 
 * PROVIDED HEREUNDER IS ON AN "AS IS" BASIS, AND NEITHER THE AUTHOR NOR
 * THE UNIVERSITY OF ILLINOIS HAS ANY OBLIGATION TO PROVIDE MAINTENANCE, 
 * SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS."
 *
 * Author:	    Steven S. Lumetta
 * Version:	    1
 * Creation Date:   19 July 2021
 * Filename:	    mp6.h
 * History:
 *	SSL	1	19 July 2021
 *		First written.
 */
#include "mp6.h"
#include <stdint.h>

//
// convert_RGB_to_HSL -- convert red, green, and blue image data into
//   HSL channels.  See documentation for specific equations to be used.
//
//   INPUTS: height -- number of rows in image
//           width -- number of columns in image
//           red -- red pixels (0-255) in column-major order
//           green -- green pixels (0-255) in column-major order
//           blue -- blue pixels (0-255) in column-major order
//   OUTPUTS: H -- hue (0-49151) in column-major order
//            S -- saturation (0-32768) in column-major order
//            L -- luma (0 to 510) in column-major order
//   RETURN VALUE: none
//   SIDE EFFECTS: none
//
uint16_t max(const uint8_t a, const uint8_t b, const uint8_t c) {
    if (a >= b && a >= c) {
        return a;
    } else if (b >= a && b >= c) {
        return b;
    } else {
        return c;
    }
}

uint16_t min(const uint8_t a, const uint8_t b, const uint8_t c) {
    if (a <= b && a <= c) {
        return a;
    } else if (b <= a && b <= c) {
        return b;
    } else {
        return c;
    }
}

uint16_t RGB_to_Luma(const uint8_t r, const uint8_t g, const uint8_t b) {
    return max(r, g, b) + min(r, g, b);
}

uint16_t RGB_to_Chro(const uint8_t r, const uint8_t g, const uint8_t b) {
    return max(r, g, b) - min(r, g, b);
}

uint16_t RGB_to_Satu(const uint8_t r, const uint8_t g, const uint8_t b) {
    uint16_t m = max(r, g, b);
    uint16_t n = min(r, g, b);
    uint16_t l = RGB_to_Luma(r, g, b);
    uint16_t c = RGB_to_Chro(r, g, b);

    if (m == 0 || n == 255) return 0;
    else if (0 < l && l <= 255) return (0x8000 * c) / l;
    else return (0x8000 * c) / (510 - l);
}

uint16_t RGB_to_Hue(const uint8_t r, const uint8_t g, const uint8_t b) {
    uint16_t m = max(r, g, b);
    // uint16_t n = min(r, g, b);
    uint16_t c = RGB_to_Chro(r, g, b);

    if (c == 0) return 0;
    else if (c > 0 && m == r) return (0x2000 * (c + g - b)) / c;
    else if (c > 0 && m > r && m == g) return (0x2000 * (3 * c + b - r)) / c;
    else return (0x2000 * (5 * c + r - g)) / c;
}

void
convert_RGB_to_HSL(int32_t height, int32_t width, const uint8_t *red,
                   const uint8_t *green, const uint8_t *blue,
                   uint16_t *H, uint16_t *S, uint16_t *L) {
    for (int i = 0; i < height * width; i++) {
        H[i] = RGB_to_Hue(red[i], green[i], blue[i]);
        S[i] = RGB_to_Satu(red[i], green[i], blue[i]);
        L[i] = RGB_to_Luma(red[i], green[i], blue[i]);
    }
}

//
// convert_HSL_to_RGB -- convert HSL channel data into red, green, and 
//   blue image data.  See documentation for specific equations to be used.
//
//   INPUTS: height -- number of rows in image
//           width -- number of columns in image
//           H -- hue (0-49151) in column-major order
//           S -- saturation (0-32768) in column-major order
//           L -- luma (0 to 510) in column-major order
//   OUTPUTS: red -- red pixels (0-255) in column-major order
//            green -- green pixels (0-255) in column-major order
//            blue -- blue pixels (0-255) in column-major order
//   RETURN VALUE: none
//   SIDE EFFECTS: none
//
uint16_t HSL_to_Chro(const uint16_t s, const uint16_t l) {
    if (l <= 255) return (s * l) / 0x8000;
    else return (s * (510 - l)) / 0x8000;
}

uint16_t HSL_to_T(const uint16_t n, const uint16_t c, const uint16_t h_minor) {
    if (h_minor >= 0x2000) return n + (c * (h_minor - 0x2000)) / 0x2000;
    else return n + (c * (0x2000 - h_minor)) / 0x2000;
}

void replace(uint8_t *r, uint8_t *g, uint8_t *b, uint8_t r_n, uint16_t g_n, uint16_t b_n) {
    *r = r_n;
    *g = g_n;
    *b = b_n;
}

void
convert_HSL_to_RGB(int32_t height, int32_t width, const uint16_t *H,
                   const uint16_t *S, const uint16_t *L,
                   uint8_t *red, uint8_t *green, uint8_t *blue) {
    for (int i = 0; i < height * width; i++) {
        uint16_t c = HSL_to_Chro(S[i], L[i]);
        uint16_t n = (L[i] - c) / 2;
        uint16_t m = n + c;

        uint16_t h_major = H[i] / 0x2000;
        uint16_t h_minor = H[i] & 0x3fff;
        uint16_t t = HSL_to_T(n, c, h_minor);

        switch (h_major) {
            case 0:
                replace(red + i, green + i, blue + i, m, n, t);
                break;
            case 1:
                replace(red + i, green + i, blue + i, m, t, n);
                break;
            case 2:
                replace(red + i, green + i, blue + i, t, m, n);
                break;
            case 3:
                replace(red + i, green + i, blue + i, n, m, t);
                break;
            case 4:
                replace(red + i, green + i, blue + i, n, t, m);
                break;
            default:
                replace(red + i, green + i, blue + i, t, n, m);
        }
    }
}

//
// compute_sobel_kernels -- compute X and Y Sobel edge detection kernels
//   using convolution.  Edge pixels may be ignored, and kernel outputs
//   for these pixels left undefined.
//
//   INPUTS: height -- number of rows in image
//           width -- number of columns in image
//           L -- luma (0-510) in column-major order
//   OUTPUTS: Gx -- Sobel X kernel pixels in column-major order
//            Gy -- Sobel Y kernel pixels in column-major order
//   RETURN VALUE: none
//   SIDE EFFECTS: none
//
int32_t x_convol(const uint16_t *center, const int32_t width) {
    int32_t convol = 0;
    convol += *(center - width - 1); // left up
    convol -= *(center - width + 1); // right up
    convol += *(center - 1) * 2; // left
    convol -= *(center + 1) * 2; // right
    convol += *(center + width - 1); // left down
    convol -= *(center + width + 1); // right down
    return convol;
}

int32_t y_convol(const uint16_t *const center, const int32_t width) {
    int32_t convol = 0;
    convol += *(center - width - 1); // left up
    convol += *(center - width + 1); // right up
    convol += *(center - width) * 2; // up
    convol -= *(center + width) * 2; // down
    convol -= *(center + width - 1); // left down
    convol -= *(center + width + 1); // right down
    return convol;
}

void
compute_sobel_kernels(int32_t height, int32_t width, const uint16_t *L,
                      int32_t *Gx, int32_t *Gy) {
    for (int row = 1; row < height - 1; row++) {
        for (int col = 1; col < width - 1; col++) {
            const uint16_t *center_L = L + row * width + col;
            int32_t *center_Gx = Gx + row * width + col;
            int32_t *center_Gy = Gy + row * width + col;
            *center_Gx = x_convol(center_L, width);
            *center_Gy = y_convol(center_L, width);
        }
    }
}

//
// equalize_intensities -- perform histogram equalization to re-map image
//   intensities.
//
//   INPUTS: height -- number of rows in image
//           width -- number of columns in image
//           L -- luma (0-510) in column-major order
//   OUTPUTS: L -- modified luma (0-510) in column-major order
//   RETURN VALUE: none
//   SIDE EFFECTS: none
//
void
equalize_intensities(int32_t height, int32_t width, uint16_t *L) {
    int64_t k[511] = {0};
    for (int i = 0; i < height * width; i++) k[L[i]]++; // count of each level
    for (int i = 1; i < 511; i++) k[i] += k[i - 1]; // cumulative count
    for (int i = 0; i < 511; i++) k[i] = (511 * k[i] + (height * width) - 1) / (height * width) - 1; // equalized level
    for (int i = 0; i < height * width; i++) L[i] = k[L[i]];
}

