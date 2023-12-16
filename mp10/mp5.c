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

// writen by zxc

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
    /* Your code goes here! */
    //verify is the return value
    //store is used for switching if x and y are different
    //sign is the sign indicator
    int32_t verify = 1;
    int32_t store = 1;
    int32_t sign = 1;
    // put the dot with smaller x value as the start
    if (x_start > x_end)
    {
        store = x_start;
        x_start = x_end;
        x_end = store;
        store = y_start;
        y_start = y_end;
        y_end = store;
    }
    if (y_end == y_start)
    {
        sign = 0;
    }
    if (y_end < y_start)
    {
        sign = -1;
    }
    //start the process of printing
    for (int32_t x = x_start; x <= x_end; x++)
    {
        int32_t y = y_start +
                    (2 * (y_end - y_start) * (x - x_start) + (x_end - x_start) * (sign)) / (2 * (x_end - x_start));
        verify &= draw_dot(x, y);
    }
    return verify;
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
    /* Your code goes here! */
    //verify is the return value
    //store is used for switching if x and y are different
    //sign is the sign indicator
    int32_t verify = 1;
    int32_t store = 1;
    int32_t sign = 1;
    if ((x_start == x_end) & (y_start == y_end))
    {
        int32_t x = x_start;
        int32_t y = y_start;
        verify &= draw_dot(x, y);
    } else
    {
        if (y_start > y_end)
        {
            store = x_start;
            x_start = x_end;
            x_end = store;
            store = y_start;
            y_start = y_end;
            y_end = store;
        }
        if (x_end == x_start)
        {
            sign = 0;
        }
        if (x_end < x_start)
        {
            sign = -1;
        }

        for (int32_t y = y_start; y <= y_end; y++)
        {
            int32_t x = x_start +
                        (2 * (x_end - x_start) * (y - y_start) + (sign) * (y_end - y_start)) / (2 * (y_end - y_start));
            verify &= draw_dot(x, y);
        }

    }
    return verify;
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
    /* Your code goes here! */
    if (abs(y_end - y_start) >= abs(x_end - x_start))
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
    /* Your code goes here! */
    if ((w < 0) || (h < 0))
    {
        return 0;
    } else
    {
        int32_t verify = 1;
        verify &= draw_line(x, y, x + w, y);
        verify &= draw_line(x, y, x, y + h);
        verify &= draw_line(x + w, y, x + w, y + h);
        verify &= draw_line(x, y + h, x + w, y + h);
        return verify;
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
    /* Your code goes here! */
    //verify is the return value
    int32_t verify = 1;
    verify &= draw_line(x_A, y_A, x_B, y_B); // A->B
    verify &= draw_line(x_A, y_A, x_C, y_C); // A->C
    verify &= draw_line(x_B, y_B, x_C, y_C); // B->C
    return verify;

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
    /* Your code goes here! */
    //verify is the return value
    int32_t verify = 1;
    int32_t x_D = x_A + x_C - x_B;
    int32_t y_D = y_A + y_C - y_B;
    verify &= draw_line(x_A, y_A, x_B, y_B);
    verify &= draw_line(x_A, y_A, x_D, y_D);
    verify &= draw_line(x_B, y_B, x_C, y_C);
    verify &= draw_line(x_C, y_C, x_D, y_D);

    return verify;
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
    /* Your code goes here!*/
    // x1 and y1 are the points to be printed
    //dist_sqr is the distance from the point to the origin
    if (inner_r < 0 || outer_r < 0 || inner_r > outer_r)
    {
        return 0;
    } else
    {
        int32_t verify = 1;
        for (int32_t x1 = x - outer_r; x1 <= x + outer_r; x1++)
        {
            for (int32_t y1 = y - outer_r; y1 <= y + outer_r; y1++)
            {
                int32_t dist_sqr = (x1 - x) * (x1 - x) + (y1 - y) * (y1 - y);
                if (dist_sqr >= (inner_r * inner_r) && dist_sqr <= (outer_r * outer_r))
                {
                    verify &= draw_dot(x1, y1);
                }
            }
        }
        return verify;
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
    /* Your code goes here! */
    // verify is the return value
    // r g b are the seperate indicators of the r g
    if (w < 0 || h < 0)
    {
        return 0;
    } else
    {
        int32_t verify = 1;
        for (int32_t x1 = x; x1 <= x + w; x1++)
        {
            int32_t dist = x1 - x;
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

            for (int32_t y1 = y; y1 <= y + h; y1++)
            {
                verify &= draw_dot(x1, y1);
            }
        }
        return verify;
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
    // verify is the return value
    int32_t verify = 0;
    set_color(0x00000);
    verify &= rect_gradient(20, 20, 30, 8, 0x000000, 0xff0000);
    verify &= rect_gradient(20, 20, 8, 90, 0x000000, 0x000000);
    verify &= rect_gradient(20, 65, 30, 8, 0x000000, 0xff0000);
    /* Your code goes here! */
    verify &= rect_gradient(92, 65, 25, 10, 0x000000, 0xff0000);
    set_color(0x000000);
    for (int32_t x = 100; x < 110; x++)
    {

        verify &= draw_line(x, 20, x - 25, 110);
    }
    for (int32_t x = 100; x < 110; x++)
    {
        verify &= draw_line(x, 20, x + 25, 110);
    }
    verify &= rect_gradient(170, 20, 60, 8, 0xff0000, 0x000000);
    verify &= rect_gradient(170, 100, 60, 8, 0x000000, 0xff0000);
    set_color(0x000000);
    for (int32_t x = 222; x < 231; x++)
    {
        verify &= draw_line(x, 28, x - 52, 99);
    }
    verify &= rect_gradient(280, 20, 8, 90, 0x000000, 0x000000);
    verify &= rect_gradient(280, 20, 40, 8, 0x000000, 0xff0000);
    verify &= rect_gradient(280, 61, 40, 8, 0x000000, 0xff0000);
    verify &= rect_gradient(280, 102, 40, 8, 0x000000, 0xff0000);
    set_color(0xb30000);
    verify &= draw_circle(300, 200, 15, 23);
    verify &= draw_circle(300, 240, 15, 23);
    verify &= rect_gradient(273, 200, 50, 40, 0xffffff, 0xffffff);
    verify &= rect_gradient(278, 200, 6, 40, 0x000000, 0x0000000);
    verify &= rect_gradient(370, 180, 8, 80, 0xff0000, 0x000000);
    verify &= rect_gradient(379, 252, 45, 8, 0x0000000, 0xff0000);
    set_color(0x00000000);
    for (int32_t x = 480; x < 489; x++)
    {
        verify &= draw_line(x, 180, x + 25, 260);
    }
    verify &= rect_gradient(475, 217, 25, 8, 0xff0000, 0x000000);
    for (int32_t x = 480; x < 489; x++)
    {
        verify &= draw_line(x, 180, x - 25, 260);
    }
    verify &= rect_gradient(540, 180, 8, 80, 0xff0000, 0x000000);
    verify &= rect_gradient(600, 180, 8, 80, 0x000000, 0xff0000);
    set_color(0);
    for (int32_t y = 180; y < 189; y++)
    {
        verify &= draw_line(549, y, 599, y + 70);

    }
    return verify;
}
