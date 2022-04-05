/*
 * 575. Distribute Candies - easy
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
    int distributeCandies(vector<int>& candyType) {
        unordered_map<int, int> umap;
        
        for (int i=0; i<candyType.size(); i++) {
            umap[candyType[i]]++;
        }
        
        int types = umap.size();
        int allowedCandies = candyType.size()/2;
        int res;
        res = min(types, allowedCandies);
        return res;
        //return max(types, (candyType.size()/2));
    }
};
