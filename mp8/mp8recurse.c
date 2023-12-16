#include <linux/limits.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

#include "mp8.h"

/**
 * Calculates the index of a 2D array given its x and y coordinates and width.
 *
 * @param x The x coordinate of the element.
 * @param y The y coordinate of the element.
 * @param width The width of the 2D array.
 *
 * @return The index of the element in the 1D array representation of the 2D array.
 */
int xy2index(int x, int y, int width)
{
    return y * width + x;
}

/**
 * Calculates the squared distance between two points in a 2D plane.
 *
 * @param x1 The x-coordinate of the first point.
 * @param y1 The y-coordinate of the first point.
 * @param x2 The x-coordinate of the second point.
 * @param y2 The y-coordinate of the second point.
 *
 * @return The squared distance between the two points.
 */
int geo_dist_sq(int x1, int y1, int x2, int y2)
{
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2); // distance squared
}

/**
 * Marks a pixel if it is not white, and returns whether it was previously marked or not.
 *
 * @param index The index of the pixel to mark.
 * @param inRed The array of red values for each pixel.
 * @param inGreen The array of green values for each pixel.
 * @param inBlue The array of blue values for each pixel.
 * @param marking The array of marks for each pixel.
 *
 * @return Return 0 if the pixel was previously unmarked, 1 if it was previously marked.
 */
uint8_t mark_w(int index, const uint8_t* inRed, const uint8_t* inGreen, const uint8_t* inBlue, uint8_t* marking)
{
    uint8_t result = 1;
    if (inRed[index] != 255 || inGreen[index] != 255 || inBlue[index] != 255) // mark if it is not white
    {
        result = marking[index];
        marking[index] = 1;
    }
    return result; // 0 for marking unmarked pixel, which means not done
}

/**
 * Marks the surrounding pixels of a given pixel and returns whether they are already marked
 *
 * @param x The x-coordinate of the pixel.
 * @param y The y-coordinate of the pixel.
 * @param width The width of the image.
 * @param inRed The array of red color values of the image.
 * @param inGreen The array of green color values of the image.
 * @param inBlue The array of blue color values of the image.
 * @param marking The array of marking values of the image.
 *
 * @return Returns 1 if all surrounding pixels have already been marked.
 */
uint8_t mark_surrounding_w(int32_t x, int32_t y, int32_t width, int32_t height, const uint8_t* inRed, const uint8_t* inGreen, const uint8_t* inBlue, uint8_t* marking)
{
    uint8_t done = 1;
    if (y > 0) done &= mark_w(xy2index(x, y-1, width), inRed, inGreen, inBlue, marking); // test up if not on top
    if (x != width - 1) done &= mark_w(xy2index(x+1, y, width), inRed, inGreen, inBlue, marking); // test right if not on right edge
    if (y < height - 1) done &= mark_w(xy2index(x, y+1, width), inRed, inGreen, inBlue, marking); // test down if not at bottom
    if (x != 0) done &= mark_w(xy2index(x-1, y, width), inRed, inGreen, inBlue, marking); // test left if not on left edge
    return done;
}

/**
 * Marks a pixel if its color is not near white, and returns the previous marking status.
 *
 * @param index The index of the pixel to mark.
 * @param distSq The maximum distance squared from white color.
 * @param inRed The array of red color values.
 * @param inGreen The array of green color values.
 * @param inBlue The array of blue color values.
 * @param marking The array of marking status for each pixel.
 *
 * @return Return 0 if the pixel was previously unmarked, 1 if it was previously marked.
 */
uint8_t mark_nw(int index, uint32_t distSq, const uint8_t* inRed, const uint8_t* inGreen, const uint8_t* inBlue, uint8_t* marking)
{
    uint8_t result = 1;
    if (!colorsWithinDistSq(inRed[index], inGreen[index], inBlue[index], 0xff, 0xff, 0xff, distSq)) // mark if it is not near white
    {
        result = marking[index];
        marking[index] = 1;
    }
    return result; // 0 for marking unmarked pixel, which means not done
}

/**
 * Marks the surrounding pixels of a given pixel and returns whether they are already marked
 *
 * @param x The x-coordinate of the pixel.
 * @param y The y-coordinate of the pixel.
 * @param width The width of the image.
 * @param distSq The maximum distance squared from white color.
 * @param inRed The array of red color values of the image.
 * @param inGreen The array of green color values of the image.
 * @param inBlue The array of blue color values of the image.
 * @param marking The array of marking values of the image.
 *
 * @return Returns 1 if all surrounding pixels have already been marked.
 */
uint8_t mark_surrounding_nw(int32_t x, int32_t y, int32_t width, int32_t height, uint32_t distSq, const uint8_t* inRed, const uint8_t* inGreen, const uint8_t* inBlue, uint8_t* marking)
{
    uint8_t done = 1;
    if (y > 0) done &= mark_nw(xy2index(x, y-1, width), distSq, inRed, inGreen, inBlue, marking); // test up if not on top
    if (x != width - 1) done &= mark_nw(xy2index(x+1, y, width), distSq, inRed, inGreen, inBlue, marking); // test right if not on right edge
    if (y < height - 1) done &= mark_nw(xy2index(x, y+1, width), distSq, inRed, inGreen, inBlue, marking); // test down if not at bottom
    if (x != 0) done &= mark_nw(xy2index(x-1, y, width), distSq, inRed, inGreen, inBlue, marking); // test left if not on left edge
    return done;
}

/**
 * Marks a pixel if it is close to the original color.
 *
 * @param index The index of the pixel to be marked.
 * @param orig The index of the original pixel.
 * @param distSq The squared distance threshold for marking.
 * @param inRed The array of red color values.
 * @param inGreen The array of green color values.
 * @param inBlue The array of blue color values.
 * @param marking The array of marking flags.
 *
 * @return 1 if the pixel is already marked, 0 otherwise.
 */
uint8_t mark_l(int index, int orig, uint32_t distSq, const uint8_t* inRed, const uint8_t* inGreen, const uint8_t* inBlue, uint8_t* marking)
{
    uint8_t result = 1;
    if (colorsWithinDistSq(inRed[index], inGreen[index], inBlue[index], inRed[orig], inGreen[orig], inBlue[orig], distSq)) // mark if it is close to the original color
    {
        result = marking[index];
        marking[index] = 1;
    }
    return result; // 0 for marking unmarked pixel, which means not done
}

/**
 * Marks surrounding pixels of a given pixel if are within the distance threshold.
 *
 * @param x The x-coordinate of the pixel to be tested.
 * @param y The y-coordinate of the pixel to be tested.
 * @param origX The x-coordinate of the original pixel.
 * @param origY The y-coordinate of the original pixel.
 * @param width The width of the image.
 * @param height The height of the image.
 * @param distSq The maximum distance squared from the original pixel.
 * @param inRed The red channel of the input image.
 * @param inGreen The green channel of the input image.
 * @param inBlue The blue channel of the input image.
 * @param marking The array to mark the pixels that meet the criteria.
 *
 * @return 1 if all surrounding pixels meet the criteria, 0 otherwise.
 */
uint8_t mark_surrounding_l(int32_t x, int32_t y, int32_t origX, int32_t origY, int32_t width, int32_t height, uint32_t distSq, const uint8_t* inRed, const uint8_t* inGreen, const uint8_t* inBlue, uint8_t* marking)
{
    uint8_t done = 1;
    int orig = xy2index(origX, origY, width);

    if ((y > 0) && (geo_dist_sq(x, y-1, origX, origY) <= 1225))
        done &= mark_l(xy2index(x, y-1, width), orig, distSq, inRed, inGreen, inBlue, marking); // test up if not on top
    if ((x != width - 1) && (geo_dist_sq(x+1, y, origX, origY) <= 1225))
        done &= mark_l(xy2index(x+1, y, width), orig, distSq, inRed, inGreen, inBlue, marking); // test right if not on right edge
    if ((y < height - 1) && (geo_dist_sq(x, y+1, origX, origY) <= 1225))
        done &= mark_l(xy2index(x, y+1, width), orig, distSq, inRed, inGreen, inBlue, marking); // test down if not at bottom
    if ((x != 0) && (geo_dist_sq(x-1, y, origX, origY) <= 1225))
        done &= mark_l(xy2index(x-1, y, width), orig, distSq, inRed, inGreen, inBlue, marking); // test left if not on left edge

    return done;
}

/*
 * basicRecurse -- flood fill recursively from a point until reaching
 *                 white or the image border
 * INPUTS: width -- width of the input image
 *         height -- height of the input image
 *         inRed -- pointer to the input red channel (1-D array)
 *         inGreen -- pointer to the input green channel (1-D array)
 *         inBlue -- pointer to the input blue channel (1-D array)
 *         x -- current x position of the flood
 *         y -- current y position of the flood
 *         marking -- array used to mark seen positions (indexed
 *                    in the same way as the RGB input arrays)
 * OUTPUTS: marking -- marked with flooded pixels
 * RETURN VALUE: none
 * SIDE EFFECTS: none
 */
void
basicRecurse (int32_t width, int32_t height,
              const uint8_t* inRed, const uint8_t* inGreen,
              const uint8_t* inBlue,
              int32_t x, int32_t y,
              uint8_t* marking)
{
    uint8_t done = 0;
    marking[xy2index(x, y, width)] = 1;

    while (done == 0) // loop until no new pixel is marked
    {
        done = 1;
        for (int x_ = 0; x_ < width; x_++)
        {
            for (int y_ = 0; y_ < height; y_++)
            {
                int index = y_ * width + x_;
                if (marking[index] == 1)
                {
                    // if a pixel is marked, try its surrounding pixels
                    done &= mark_surrounding_w(x_, y_, width, height, inRed, inGreen, inBlue, marking);
                }
            }
        }
    }
}


/*
 * greyRecurse -- flood fill recursively from a point until reaching
 *                near-white pixels or the image border
 * INPUTS: width -- width of the input image
 *         height -- height of the input image
 *         inRed -- pointer to the input red channel (1-D array)
 *         inGreen -- pointer to the input green channel (1-D array)
 *         inBlue -- pointer to the input blue channel (1-D array)
 *         x -- current x position of the flood
 *         y -- current y position of the flood
 *         distSq -- maximum distance squared between white and boundary
 *                   pixel color
 *         marking -- array used to mark seen positions (indexed
 *                    in the same way as the RGB input arrays)
 * OUTPUTS: marking -- marked with flooded pixels
 * RETURN VALUE: none
 * SIDE EFFECTS: none
 */
void
greyRecurse (int32_t width, int32_t height,
             const uint8_t* inRed, const uint8_t* inGreen,
             const uint8_t* inBlue,
             int32_t x, int32_t y, uint32_t distSq,
             uint8_t* marking)
{
    uint8_t done = 0;
    marking[xy2index(x, y, width)] = 1;

    while (done == 0) // loop until no new pixel is marked
    {
        done = 1;
        for (int x_ = 0; x_ < width; x_++)
        {
            for (int y_ = 0; y_ < height; y_++)
            {
                int index = y_ * width + x_;
                if (marking[index] == 1)
                {
                    // if a pixel is marked, try its surrounding pixels
                    done &= mark_surrounding_nw(x_, y_, width, height, distSq, inRed, inGreen, inBlue, marking);
                }
            }
        }
    }
}


/*
 * limitedRecurse -- flood fill recursively from a point until reaching
 *                   pixels too different (in RGB color) from the color at
 *                   the flood start point, too far away (> 35 pixels), or
 *                   beyond the image border
 * INPUTS: width -- width of the input image
 *         height -- height of the input image
 *         inRed -- pointer to the input red channel (1-D array)
 *         inGreen -- pointer to the input green channel (1-D array)
 *         inBlue -- pointer to the input blue channel (1-D array)
 *         origX -- starting x position of the flood
 *         origY -- starting y position of the flood
 *         x -- current x position of the flood
 *         y -- current y position of the flood
 *         distSq -- maximum distance squared between pixel at origin
 *                   and boundary pixel color
 *         marking -- array used to mark seen positions (indexed
 *                    in the same way as the RGB input arrays)
 * OUTPUTS: marking -- marked with flooded pixels
 * RETURN VALUE: none
 * SIDE EFFECTS: none
 */
void
limitedRecurse (int32_t width, int32_t height,
                const uint8_t* inRed, const uint8_t* inGreen,
                const uint8_t* inBlue,
                int32_t origX, int32_t origY, int32_t x, int32_t y,
                uint32_t distSq, uint8_t* marking)
{
	uint8_t done = 0;
	marking[xy2index(x, y, width)] = 1;

	while (done == 0) // loop until no new pixel is marked
	{
		done = 1;
		for (int x_ = 0; x_ < width; x_++)
		{
			for (int y_ = 0; y_ < height; y_++)
			{
				int index = y_ * width + x_;
				if (marking[index] == 1)
				{
					// if a pixel is marked, try its surrounding pixels
                    done &= mark_surrounding_l(x_, y_, origX, origY, width, height, distSq, inRed, inGreen, inBlue, marking);
				}
			}
		}
	}
}