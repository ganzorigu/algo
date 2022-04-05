// 485. Max Consecutive Ones
// Given a binary array, find the maximum number of consecutive 1s in this array.
// Input: [1,1,0,1,1,1]
// Output: 3

#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxOnes = 0;
        int cnt = 0;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i]==1) {
                cnt++;
            } else {
                maxOnes = max(cnt, maxOnes);
                cnt = 0;
            }                        
        }
        maxOnes = max(cnt, maxOnes);
        
        return maxOnes;
        
    }
};