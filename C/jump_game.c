#include <stdio.h>
#include <stdbool.h>

// Function to check if you can reach the last index
bool canJump(int *nums, int numsSize)
{
    int maxReach = 0;  // Variable to store the maximum reachable index

    for (int i = 0; i < numsSize; i++)
    {
        // If current index is beyond the maximum reachable index, return false
        if (i > maxReach)
        {
            return false;
        }

        // Update the maximum reachable index
        maxReach = (i + nums[i] > maxReach) ? (i + nums[i]) : maxReach;

        // If we can reach or go beyond the last index, return true
        if (maxReach >= numsSize - 1)
        {
            return true;
        }
    }

    return false;  // If we exit the loop and haven't returned true, we can't reach the end
}

int main()
{
    int nums[] = {2, 3, 1, 1, 4};  // Example input array
    int numsSize = sizeof(nums) / sizeof(nums[0]);  // Size of the array

    // Check if it's possible to reach the last index
    if (canJump(nums, numsSize))
    {
        printf("Yes, you can reach the end of the array!\n");
    }
    else
    {
        printf("No, you cannot reach the end of the array.\n");
    }

    return 0;
}
