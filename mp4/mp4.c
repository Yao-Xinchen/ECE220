#include "mp4.h"
#include <stdio.h>

/**
 * Replaces the values in an array with new values.
 *
 * @param nums The array to be modified.
 * @param new_nums The array containing the new values.
 */
void replace(int *nums, int const *new_nums)
{
    for (int i = 0; i < 4; i++)
    {
        nums[i] = new_nums[i];
    }
}

/**
 * Compares two sets of integers based on a set of weights and replaces the first set with the second set if it is "better".
 * "Better" is defined as having a smaller weighted sum,
    or if the weighted sums are equal, having a smaller sum of the integers,
    or if both of those are equal, having a larger first integer,
    or if that is also equal, having a larger second integer,
    and so on.
 *
 * @param nums Pointer to the first set of integers.
 * @param new_nums Pointer to the second set of integers.
 * @param s1 Weight for the first integer in each set.
 * @param s2 Weight for the second integer in each set.
 * @param s3 Weight for the third integer in each set.
 * @param s4 Weight for the fourth integer in each set.
 */
void compare(int *nums, int *new_nums, int32_t s1, int32_t s2, int32_t s3, int32_t s4)
{
    int value = nums[0] * s1 + nums[1] * s2 + nums[2] * s3 + nums[3] * s4;
    int new_value = new_nums[0] * s1 + new_nums[1] * s2 + new_nums[2] * s3 + new_nums[3] * s4;
    int num_sum = nums[0] + nums[1] + nums[2] + nums[3];
    int new_num_sum = new_nums[0] + new_nums[1] + new_nums[2] + new_nums[3];

    if (new_value < value)
    {
        replace(nums, new_nums);
    } else if (new_value == value)
    {
        if (new_num_sum < num_sum)
        {
            replace(nums, new_nums);
        } else if (new_num_sum == num_sum)
        {
            if (new_nums[0] > nums[0])
            {
                replace(nums, new_nums);
            } else if (new_nums[0] == nums[0])
            {
                if (new_nums[1] > nums[1])
                {
                    replace(nums, new_nums);
                } else if (new_nums[1] == nums[1])
                {
                    if (new_nums[2] > nums[2])
                    {
                        replace(nums, new_nums);
                    } else if (new_nums[2] == nums[2])
                    {
                        if (new_nums[3] > nums[3])
                        {
                            replace(nums, new_nums);
                        }
                    }
                }
            }
        }
    }
}

int32_t print_stamps(int32_t amount, int32_t s1, int32_t s2, int32_t s3, int32_t s4)
{
    int nums[4];
    int new_nums[4];

    nums[0] = amount / s1 + 2; // so that the first compare will always replace
    nums[1] = 0;
    nums[2] = 0;
    nums[3] = 0;

    // iterate through all possible combinations of stamps
    int max_s1 = amount / s1 + 1;
    for (int i = 0; i <= max_s1; i++)
    {
        int max_s2 = (amount - i * s1) / s2 + 1;
        for (int j = 0; j <= max_s2; j++)
        {
            int max_s3 = (amount - i * s1 - j * s2) / s3 + 1;
            for (int k = 0; k <= max_s3; k++)
            {
                int max_s4 = (amount - i * s1 - j * s2 - k * s3) / s4 + 1;
                for (int l = 0; l <= max_s4; l++)
                {
                    if (i * s1 + j * s2 + k * s3 + l * s4 >= amount) // check whether the combination is valid
                    {
                        new_nums[0] = i;
                        new_nums[1] = j;
                        new_nums[2] = k;
                        new_nums[3] = l;
                        compare(nums, new_nums, s1, s2, s3, s4);
                    }
                }
            }
        }
    }

    int value = nums[0] * s1 + nums[1] * s2 + nums[2] * s3 + nums[3] * s4;
    printf("%d %d %d %d -> %d\n", nums[0], nums[1], nums[2], nums[3], value);

    return value == amount ? 1 : 0; // return 0 if exact match is not possible
}