// 48. Rotate Image
// You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
// You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

// Solution: shift left, top row, right column,bottom row, left column shift right,
// need 4 variables to hold, corner values, because it will be overwritten
// after finishing outer layer, go inside. 
#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>
#include <unordered_map>

using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {     
        // boundary of shifting,
        // after 90 degree rotation, need to update these values, to enter inner layer
        int xStart=0, yStart=0, xEnd=matrix.size()-1, yEnd=matrix.size()-1;                     
        
        // tempX holds value of 4 corners of matrix;
        // after 1 place shifting, +1 position has to be copied.
        // shiftTimes - number of times required to shift, to achieve 90 degree
        int temp1, temp2, temp3, temp4;        
        int shiftTimes = matrix.size();
        
        while(xStart<xEnd) {
            for (int k=1; k<shiftTimes; k++) {
                // top row shift left
                int i = xEnd;
                int j = yStart;        
                temp1 = matrix[yStart][xEnd];
                while(i-1>xStart) {
                    matrix[j][i] = matrix[j][i-1];
                    i--;
                }                
                // right column shift left
                i = xEnd;
                j = yEnd;
                temp2 = matrix[yEnd][xEnd];
                while(j-1>yStart) {            
                    matrix[j][i] = matrix[j-1][i];
                    j--;
                }

                // bottom row shift left
                i = xStart;
                j = yEnd;
                temp3 = matrix[yEnd][xStart];
                while(i+1<xEnd) {            
                    matrix[j][i] = matrix[j][i+1];
                    i++;
                }

                // left column shift left
                i = xStart;
                j = yStart;
                temp4 = matrix[yStart][xStart];
                while(j+1<yEnd) {            
                    matrix[j][i] = matrix[j+1][i];
                    j++;
                }
                matrix[yStart][xStart+1] = temp4;  
                matrix[yStart+1][xEnd] = temp1;
                matrix[yEnd][xEnd-1] = temp2;
                matrix[yEnd-1][xStart] = temp3;
           }  
            shiftTimes = shiftTimes - 2;
            xStart++;
            xEnd--;
            yStart++;
            yEnd--;
        }
        
    }
};