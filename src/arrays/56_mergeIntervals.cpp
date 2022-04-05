// 56. Merge Intervals
// Given an array of intervals where intervals[i] = [starti, endi], 
// merge all overlapping intervals, and return an array of the non-overlapping 
// intervals that cover all the intervals in the input.

// Solution: My initial solution was not good. because i didn't sort the array
// Therefore after each merge, I have to check whole array again.
// my solution was O(n^3).

// if the array is sorted, we just need loop the array just once. 
// Therefore solution becomes O(n^2)

#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        vector<bool> merged(intervals.size(), false);
        
        int n = intervals.size();
        vector<int> *highElement, *lowElement;        
        int left, right;
        vector<int> temp(2,0);
        
        sort(intervals.begin(), intervals.end());
        
        int j;        
        for (int i=0; i<intervals.size(); i++) {
            if (merged[i]) {
                // no need to check further if merged
                continue;
            }
            temp[0] = intervals[i][0];
            temp[1] = intervals[i][1];
            
            j=i;            
            while(j<n-1){
                j++;                
                if (!merged[j]) {
                    // checking if two ranges are overlapping
                    // simple code
                    if (temp[1] >= intervals[j][0]) {
                        // there is overlap
                        temp[1] = max(temp[1], intervals[j][1]);
                        merged[j] = true;
                    }
                                        
                    // checking if two ranges are overlapping *****
                    // hard to understand, but time complexity same ****
                    // if (temp[1] > intervals[j][1]) {
                    //     highElement = &temp;
                    //     lowElement = &intervals[j];
                    // } else {
                    //     highElement = &intervals[j];
                    //     lowElement = &temp;
                    // }
                    //  if ((*highElement)[0] <= (*lowElement)[1]) {
                    //      // overlap exist. temp[0], temp[1] are the merged array
                    //     if ((*highElement)[0] <= (*lowElement)[0]) {                            
                    //         temp[0] = (*highElement)[0]; 
                    //     } else {                            
                    //         temp[0] = (*lowElement)[0]; 
                    //     }
                    //     temp[1] = (*highElement)[1];                        
                    //      // mark the merged element
                    //     merged[j] = true;
                    //      // if overlap happens, check again from the array element next to it. [if sorted, no longer needed]
                    //     //j = i;                                
                    // }                      
                    // **************************************************
                }                
            }
            // merged output should be put inside result array
            result.push_back(temp);                        
        }
        return result;
    }       
};