/*									tab:8
 *
 * main.c - skeleton source file for ECE220 picture drawing program
 *
 * "Copyright (c) 2018 by Charles H. Zega, and Saransh Sinha."
 *
 * Permission to use, copy, modify, and distribute this software and its
 * documentation for any purpose, without fee, and without written agreement is
 * hereby granted, provided that the above copyright notice and the following
 * two paragraphs appear in all copies of this software.
 * 
 * IN NO EVENT SHALL THE AUTHOR OR THE UNIVERSITY OF ILLINOIS BE LIABLE TO 
 * ANY PARTY FOR DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL 
 * DAMAGES ARISING OUT  OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, 
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
 * Author:	    Charles Zega, Saransh Sinha
 * Version:	    1
 * Creation Date:   12 February 2018
 * Filename:	    mp5.h
 * History:
 *	CZ	1	12 February 2018
 *		First written.
 */
#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include "mp5.h"

/*
	You must write all your code only in this file, for all the functions!
*/



/* 
 *  near_horizontal
 *	 
 *	 
 *	
 *	
 * INPUTS: x_start,y_start -- the coordinates of the pixel at one end of the line
 * 	   x_end, y_end    -- the coordinates of the pixel at the other end
 * OUTPUTS: draws a pixel to all points in between the two given pixels including
 *          the end points
 * RETURN VALUE: 0 if any of the pixels drawn are out of bounds, otherwise 1
 * SIDE EFFECTS: none
 */

int32_t near_horizontal(int32_t x_start, int32_t y_start, int32_t x_end, int32_t y_end)
{
    int32_t result = 1;

    if (x_start > x_end)
    {
        int32_t temp = x_start;
        x_start = x_end;
        x_end = temp;
        temp = y_start;
        y_start = y_end;
        y_end = temp;
    } // let x_start always < x_end, x1 = x_start, x2 = x_end, y1 = y_start, y2 = y_end

    int sign = (y_end - y_start) > 0 ? 1 : -1;

    for (int32_t x = x_start; x <= x_end; x++)
    {
        int32_t y =
                y_start + (2 * (y_end - y_start) * (x - x_start) + (x_end - x_start) * sign) / (2 * (x_end - x_start));
        result &= draw_dot(x, y);
    }
    return result;
}


/* 
 *  near_vertical
 *	 
 *	 
 *	
 *	
 * INPUTS: x_start,y_start -- the coordinates of the pixel at one end of the line
 * 	   x_end, y_end    -- the coordinates of the pixel at the other end
 * OUTPUTS: draws a pixel to all points in between the two given pixels including
 *          the end points
 * RETURN VALUE: 0 if any of the pixels drawn are out of bounds, otherwise 1
 * SIDE EFFECTS: none
 */

int32_t near_vertical(int32_t x_start, int32_t y_start, int32_t x_end, int32_t y_end)
{
    int32_t result = 1;

    if (x_start == x_end)
    {
        for (int32_t y = y_start; y <= y_end; y++)
        {
            result &= draw_dot(x_start, y);
        }
    } else
    {
        if (y_start > y_end)
        {
            int32_t temp = x_start;
            x_start = x_end;
            x_end = temp;
            temp = y_start;
            y_start = y_end;
            y_end = temp;
        } // let y_start always < y_end, x1 = x_start, x2 = x_end, y1 = y_start, y2 = y_end

        int sign = (x_end - x_start) > 0 ? 1 : -1;

        for (int32_t y = y_start; y <= y_end; y++)
        {
            int32_t x = x_start +
                        (2 * (x_end - x_start) * (y - y_start) + (y_end - y_start) * sign) / (2 * (y_end - y_start));
            result &= draw_dot(x, y);
        }
    }
    return result;
}

/* 
 *  draw_line
 *	 
 *	 
 *	
 *	
 * INPUTS: x_start,y_start -- the coordinates of the pixel at one end of the line
 * 	   x_end, y_end    -- the coordinates of the pixel at the other end
 * OUTPUTS: draws a pixel to all points in between the two given pixels including
 *          the end points
 * RETURN VALUE: 0 if any of the pixels drawn are out of bounds, otherwise 1
 * SIDE EFFECTS: none
 */

int32_t draw_line(int32_t x_start, int32_t y_start, int32_t x_end, int32_t y_end)
{
    if (abs(y_end - y_start) > abs(x_end - x_start))
    {
        return near_vertical(x_start, y_start, x_end, y_end);
    } else
    {
        return near_horizontal(x_start, y_start, x_end, y_end);
    }
}


/* 
 *  draw_rect
 *	 
 *	 
 *	
 *	
 * INPUTS: x,y -- the coordinates of the top-left pixel of the rectangle
 *         w,h -- the width and height, respectively, of the rectangle
 * OUTPUTS: draws a pixel to every point of the edges of the rectangle
 * RETURN VALUE: 0 if any of the pixels drawn are out of bounds, otherwise 1
 * SIDE EFFECTS: none
 */

int32_t draw_rect(int32_t x, int32_t y, int32_t w, int32_t h)
{
    if (w < 0 || h < 0)
    {
        return 0;
    } else
    {
        int32_t result = 1;
        result &= draw_line(x, y, x + w, y);
        result &= draw_line(x, y, x, y + h);
        result &= draw_line(x + w, y, x + w, y + h);
        result &= draw_line(x, y + h, x + w, y + h);
        return result;
    }
}


/* 
 *  draw_triangle
 *	 
 *	 
 *	
 *	
 * INPUTS: x_A,y_A -- the coordinates of one of the vertices of the triangle
 *         x_B,y_B -- the coordinates of another of the vertices of the triangle
 *         x_C,y_C -- the coordinates of the final of the vertices of the triangle
 * OUTPUTS: draws a pixel to every point of the edges of the triangle
 * RETURN VALUE: 0 if any of the pixels drawn are out of bounds, otherwise 1
 * SIDE EFFECTS: none
 */

int32_t draw_triangle(int32_t x_A, int32_t y_A, int32_t x_B, int32_t y_B, int32_t x_C, int32_t y_C)
{
    int32_t result = 1;
    result &= draw_line(x_A, y_A, x_B, y_B); // A->B
    result &= draw_line(x_C, y_C, x_A, y_A); // C->A
    result &= draw_line(x_B, y_B, x_C, y_C); // B->C
    return result;
}

/* 
 *  draw_parallelogram
 *	 
 *	 
 *	
 *	
 * INPUTS: x_A,y_A -- the coordinates of one of the vertices of the parallelogram
 *         x_B,y_B -- the coordinates of another of the vertices of the parallelogram
 *         x_C,y_C -- the coordinates of another of the vertices of the parallelogram
 * OUTPUTS: draws a pixel to every point of the edges of the parallelogram
 * RETURN VALUE: 0 if any of the pixels drawn are out of bounds, otherwise 1
 * SIDE EFFECTS: none
 */

int32_t draw_parallelogram(int32_t x_A, int32_t y_A, int32_t x_B, int32_t y_B, int32_t x_C, int32_t y_C)
{
    int32_t result = 1;
    int32_t x_D = x_A + x_C - x_B;
    int32_t y_D = y_A + y_C - y_B;
    result &= draw_line(x_A, y_A, x_B, y_B); // A->B
    result &= draw_line(x_A, y_A, x_D, y_D); // A->D
    result &= draw_line(x_B, y_B, x_C, y_C); // B->C
    result &= draw_line(x_C, y_C, x_D, y_D); // C->D
    return result;
}


/* 
 *  draw_circle
 *	 
 *	 
 *	
 *	
 * INPUTS: x,y -- the center of the circle
 *         inner_r,outer_r -- the inner and outer radius of the circle
 * OUTPUTS: draws a pixel to every point whose distance from the center is
 * 	    greater than or equal to inner_r and less than or equal to outer_r
 * RETURN VALUE: 0 if any of the pixels drawn are out of bounds, otherwise 1
 * SIDE EFFECTS: none
 */

int32_t draw_circle(int32_t x, int32_t y, int32_t inner_r, int32_t outer_r)
{
    if (inner_r < 0 || outer_r < 0 || inner_r > outer_r)
    {
        return 0;
    } else
    {
        int32_t result = 1;
        for (int32_t i = x - outer_r; i <= x + outer_r; i++)
        {
            for (int32_t j = y - outer_r; j <= y + outer_r; j++)
            {
                int32_t dist_sqr = (i - x) * (i - x) + (j - y) * (j - y);
                if (dist_sqr >= (inner_r * inner_r) && dist_sqr <= (outer_r * outer_r)) result &= draw_dot(i, j);
            }
        }
        return result;
    }
}


/* 
 *  rect_gradient
 *	 
 *	 
 *	
 *	
 * INPUTS: x,y -- the coordinates of the top-left pixel of the rectangle
 *         w,h -- the width and height, respectively, of the rectangle
 *         start_color -- the color of the far left side of the rectangle
 *         end_color -- the color of the far right side of the rectangle
 * OUTPUTS: fills every pixel within the bounds of the rectangle with a color
 *	    based on its position within the rectangle and the difference in
 *          color between start_color and end_color
 * RETURN VALUE: 0 if any of the pixels drawn are out of bounds, otherwise 1
 * SIDE EFFECTS: none
 */

int32_t rect_gradient(int32_t x, int32_t y, int32_t w, int32_t h, int32_t start_color, int32_t end_color)
{
    if (w < 0 || h < 0)
    {
        return 0;
    } else
    {
        int32_t result = 1;
        for (int32_t i = x; i <= x + w; i++)
        {
            int32_t dist = i - x;
            int32_t start_r = (start_color & 0x00FF0000) >> 16;
            int32_t start_g = (start_color & 0x0000FF00) >> 8;
            int32_t start_b = start_color & 0x000000FF;
            int32_t end_r = (end_color & 0x00FF0000) >> 16;
            int32_t end_g = (end_color & 0x0000FF00) >> 8;
            int32_t end_b = end_color & 0x000000FF;

            int32_t sign_r = (end_r - start_r) > 0 ? 1 : -1;
            int32_t sign_g = (end_g - start_g) > 0 ? 1 : -1;
            int32_t sign_b = (end_b - start_b) > 0 ? 1 : -1;

            int32_t r = start_r + (2 * dist * (end_r - start_r) + w * sign_r) / (2 * w);
            int32_t g = start_g + (2 * dist * (end_g - start_g) + w * sign_g) / (2 * w);
            int32_t b = start_b + (2 * dist * (end_b - start_b) + w * sign_b) / (2 * w);

            int32_t color = (r << 16) + (g << 8) + b;
            set_color(color);

            for (int32_t j = y; j <= y + h; j++)
            {
                result &= draw_dot(i, j);
            }
        }
        return result;
    }
}


/* 
 *  draw_picture
 *	 
 *	 
 *	
 *	
 * INPUTS: none
 * OUTPUTS: alters the image by calling any of the other functions in the file
 * RETURN VALUE: 0 if any of the pixels drawn are out of bounds, otherwise 1
 * SIDE EFFECTS: none
 */


int32_t draw_picture()
{
    // set black color
    set_color(0x00000000);
    // draw "Y"
    draw_parallelogram(20, 100, 40, 100, 70, 160);
    draw_parallelogram(80, 100, 100, 100, 70, 160);
    draw_rect(50, 160, 20, 60);
    // draw "A"
    draw_parallelogram(140, 100, 160, 100, 120, 220);
    draw_parallelogram(140, 100, 160, 100, 200, 220);
    draw_rect(115, 180, 70, 20);
    // draw "O"
    draw_circle(260, 160, 40, 60);
    set_color(0x00FFFFFF);
    draw_circle(260, 160, 41, 59);
    set_color(0x00000000);
    // draw "X"
    draw_parallelogram(400, 100, 420, 100, 480, 220);
    draw_parallelogram(460, 100, 480, 100, 420, 220);
    // draw "I"
    draw_rect(500, 100, 20, 120);
    // draw "N"
    draw_rect(540, 100, 20, 120);
    draw_rect(600, 100, 20, 120);
    draw_parallelogram(560, 100, 600, 180, 600, 220);

    return 0;
}
