// 695. Max Area of Island
// Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.)
// You may assume all four edges of the grid are surrounded by water.

// Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)

// Solution: recursive and dp Solution
// created auxillary array to mark if array element is visited before.
// Note: need to mark visited before recursive calls.
#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {        
                        
        vector<vector<bool>> visitedGrid(grid.size(), vector<bool> (grid[0].size(), false));
                
        int maxArea = 0;
        
        for (int i=0; i<grid.size(); i++) {
            for (int j=0; j<grid[0].size(); j++) {
                if (grid[i][j]==1 && !visitedGrid[i][j]) {
                    // only check if island is checked before.
                    maxArea = max(maxArea, recursiveIslandSize(grid, visitedGrid, i,j));
                }                
            }
        }                 
        return maxArea;

    }
    
    int recursiveIslandSize(vector<vector<int>>& grid, vector<vector<bool>>& visitedGrid, int x, int y) {        
        // if 0, boundary is reached
        if (grid[x][y]==0) {
            return 0;
        }                
        
        // we should not count, one that is already counted
        if (visitedGrid[x][y]) {         
            return 0;
        }        
        
        int right=0, bottom=0, left=0, top=0;
        // mark it visited
        visitedGrid[x][y] = true;
        
        // need to check top, bottom, left, right direction.        
        if (x+1 < grid.size() && !visitedGrid[x+1][y]) {
            bottom = recursiveIslandSize(grid, visitedGrid, x+1, y);
        }
        
        if (x-1 >=0 && !visitedGrid[x-1][y]) {
            top = recursiveIslandSize(grid, visitedGrid, x-1, y);
        }
                        
        if (y+1 < grid[0].size() && !visitedGrid[x][y+1]) {
            right = recursiveIslandSize(grid, visitedGrid, x, y+1);
        }
        
        if (y-1 >= 0 && !visitedGrid[x][y-1]) {
            left = recursiveIslandSize(grid, visitedGrid, x, y-1);
        }
        
        return 1 + left + right + bottom + top;                                
    }
    
};