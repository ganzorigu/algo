// 238. Product of Array Except Self
// used 2 extra array,
// and store the product at each index from start and the beginning
// product of these arrays are the result.

#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix(nums.size(), 0);
        vector<int> suffix(nums.size(), 0);
        
        prefix[0] = 1;
        int p = 1;
        for (int i=1; i<nums.size(); i++) {
            p *= nums[i-1];
            prefix[i] = p;
        }
        
        suffix[nums.size()-1] = 1;
        p = 1;
        for (int i=nums.size()-2; i>=0; i--) {
            p *= nums[i+1];
            suffix[i] = p;
        }
        
        for (int i=0; i<nums.size(); i++) {
            prefix[i] = prefix[i] * suffix[i];
        }
        
        return prefix;
        
    }
};
