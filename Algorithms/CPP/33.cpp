// Author :  Accagain
// Date   :  17/2/17
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 * 
 * Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
 *
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 *
 * You are given a target value to search. If found in the array return its index, otherwise return -1.
 *
 * You may assume no duplicate exists in the array.
 *
 * 做法：
 *      
 * 时间复杂度：
 *          O(N)
 * 
****************************************************************************************/

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

#define INF 0x3fffffff

using namespace std;

class Solution {
public:

    int search(vector<int> &nums, int target) {

        int l = 0, r = nums.size() - 1;
        int ans = -1;

        while (l <= r) {

            int mid = (l + r) / 2;

            //printf("%d %d\n", mid, nums[mid]);

            if (target == nums[mid]) {
                ans = mid;
                break;
            } else if (nums[l] <= nums[mid]) {
                if (target >= nums[l] && target < nums[mid])
                    r = mid - 1;
                else
                    l = mid + 1;
            } else {
                if (target > nums[mid] && target <= nums[r])
                    l = mid + 1;
                else
                    r = mid - 1;
            }

        }
        return ans;
    }

    int searchN(vector<int>& nums, int target) {
        int ans = -1;
        for(int i=0; i<nums.size(); i++)
        {
            if(target == nums[i])
                ans = i;
        }
        return ans;
    }
};