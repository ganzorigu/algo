// 287. Find the Duplicate Number

// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

// There is only one repeated number in nums, return this repeated number.

#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
                
        sort(nums.begin(), nums.end());
        int prev = 0;
        for (int i=0; i<nums.size(); i++) {
            if (prev == nums[i]) {
                return prev;
            }
            prev = nums[i];
            
        }
        return prev;        
        
    }
};