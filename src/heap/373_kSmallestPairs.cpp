/*
 * 373. Find K Pairs with Smallest Sums
 * */

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;


class comparator{
public:
    bool operator()(pair<int,int> &lhs, pair<int,int> &rhs) {
        return lhs.first+lhs.second < rhs.first+rhs.second;
    }
};


class myComparison {
    bool min_queue;
public:
    myComparison(const bool& min_q=false) {
        min_queue=min_q;
    }
    bool operator()(const pair<int,int>& lhs, const pair<int, int> &rhs) {
        if (min_queue) return (lhs.first+lhs.second > rhs.first + rhs.second);
        else return (lhs.first+lhs.second < rhs.first + rhs.second);
    }
};
class Solution {
public:    
    
//     vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
//         vector<vector<int>> result;
//         if (nums1.size()==0 || nums2.size()==0) {
//             return result;
//         }
// //         if (nums1.size()*nums2.size()<k) {
// //             return result;
// //         }
        
        
        
//         vector<pair<int, int>> allPairs;
        
//         for (int i=0; i<nums1.size(); i++) {
//             for (int j=0; j<nums2.size(); j++) {
//                 allPairs.push_back(make_pair(nums1[i], nums2[j]));
//             }
//         }
        
//         sort(allPairs.begin(), allPairs.end(), comparator());
        
//         int length = allPairs.size() < k ? allPairs.size() : k;
        
//         for (int i=0; i<length; i++) {
//             vector<int> temp;
//             temp.push_back(allPairs[i].first);
//             temp.push_back(allPairs[i].second);
//             result.push_back(temp);
//         }
        
//         return result;
//     }
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, myComparison> q;
        for (int i=0; i<nums1.size(); i++) {
            for (int j=0; j<nums2.size(); j++) {
                if (q.size()<k) {
                    q.push(make_pair(nums1[i],nums2[j]));
                } else {
                    auto top_pair = q.top();
                    if (top_pair.first + top_pair.second > nums1[i] + nums2[j]) {
                        q.pop();
                        q.push(make_pair(nums1[i],nums2[j]));
                    }
                }
            }
        }
        
        if (q.size()==0) return vector<vector<int>>();
        // q has the min k pairs
        // q.top() max of theses min k pairs
        // returns [pair_1, pair_2, .... pair_k]
            
            
        vector<vector<int>> returns;
        
        // int i = q.size() -1;
        
        while(!q.empty()) {
            vector<int> temp;
            temp.push_back(q.top().first);
            temp.push_back(q.top().second);
            returns.push_back(temp);          
            q.pop();            
        }
        
        return returns;
        
        
    }
    
};
