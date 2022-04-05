// 54. Spiral Matrix
// Given an m x n matrix, return all elements of the matrix in spiral order.

// Solution 
// declare 4 variable to hold left, right, top, down boundary.
// based on the direction, check the related boundary
// used switch case;

#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        // number of elements are m*n;
        int numberOfElements = matrix.size() * matrix[0].size();
        // result array
        vector<int> result;
        
        // need to have 4 boundary
        int x_right=matrix[0].size();
        int x_left = 0;
        int y_top = 0;
        int y_bot = matrix.size();
        
        // directions are changed right=0, down=1, left=2, top=3
        enum direction{right, down, left, up};
        direction dir = right;
        
        int i=0, j=0;
        
        while(numberOfElements > 0) {
            result.push_back(matrix[j][i]);
            numberOfElements--;
            switch(dir) {
                case 0:
                    // right 
                    if (i<x_right-1) {
                        i++;                                                                        
                    } else {
                        j++;
                        x_right--;
                        dir=down;
                    }
                    break;
                case 1:
                    // down
                    if (j<y_bot-1) {
                        j++;                                               
                    } else {
                        i--;
                        y_bot--;
                        dir=left;
                    }                                        
                    break;                    
                case 2:
                    // left
                    if (i>x_left) {
                        i--;                        
                    } else {
                        j--;
                        x_left++;
                        dir=up;
                    }                                        
                    break;
                case 3:
                    // up
                    if (j>y_top+1) {
                        j--;                        
                    } else {
                        i++;
                        y_top++;
                        dir=right;
                    }                                        
                    break;
                default:
                    break;
            }            
        }
        return result;    
    }
};