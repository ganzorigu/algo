/*
 * 2220_minBitFlips.cpp
 *
 *  Created on: Apr 7, 2022
 *      Author: ganzo
 */
/*
 * 2220. Minimum Bit Flips to Convert Number
 * */

#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int temp = start ^ goal;
        int count = 0;
        for (auto i=0; i<sizeof(int)*8; i++) {
            if (temp & (1<<0)) {
                count++;
            }
            temp = temp >> 1;
        }
        return count;
    }
};

int main() {
	Solution sol;
	cout << sol.minBitFlips(10,7) << endl;
	return 0;
}


