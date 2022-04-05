/*
 * 496. Next Greater Element I - easy
 * */


#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//         // vector<int> result;
//         // int k;
//         // for (int i=0; i<nums1.size(); i++) {
//         //     for (int j=0; j<nums2.size(); j++) {
//         //         if (nums1[i]==nums2[j]) {
//         //             k = j+1;
//         //             while(k<nums2.size() && nums1[i] >= nums2[k]) {
//         //                 k++;
//         //             }
//         //             if (k==nums2.size()) {
//         //                 result.push_back(-1);
//         //             } else {
//         //                 result.push_back(nums2[k]);
//         //             }                    
//         //         }
//         //     }
//         // }
//         // return result;
        
//         vector<int> result;
//         stack<int> st;                
//         int greater=-1;
//         int j;
//         for (int i=0; i<nums1.size(); i++) {
//             j = nums2.size()-1;
//             greater=-1;
//             while(nums2[j] != nums1[i]) {
//                 if (nums2[j] > nums1[i]) {
//                     greater = nums2[j];
//                 }
//                 j--;
//             }
//             result.push_back(greater);
//         }
        
//         return result;
//     }
    
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
    {
        std::stack<int> sk;
        std::unordered_map<int, int> h;
        for(auto i : nums2)
        {
            while(!sk.empty() && sk.top() < i)
            {
                h[sk.top()] = i;
                sk.pop();
            }
            sk.push(i);
        }
        std::vector<int> r;
        for(auto i: nums1)
        {
            auto itr = h.find(i);
            if(itr != h.end())
            {
                r.push_back(itr->second);
            }
            else
            {
                r.push_back(-1);
            }
        }
        return r;
    }
    
    
};
