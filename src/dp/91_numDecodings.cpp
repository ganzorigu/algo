/*
 * 91_numDecodings.cpp - Linear DP
 *
 *  Created on: Apr 11, 2022
 *      Author: ganzo
 */
#include <algorithm> // std::sort
#include <iostream>  // std::cout
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {

  int recursiveCntDecodings(string &decoded, vector<int> &dp, uint16_t index) {
    if (decoded.size() == index) {
      return 1;
    }
    if (!dp[index]) { // if intermediate result not exist
      int a = 0, b = 0;
      uint8_t curr_val, next_val;
      curr_val = decoded[index] - '0';
      next_val = decoded[index + 1] - '0';

      if (curr_val != 0 && (curr_val * 10 + next_val) <= 26 &&
          index < decoded.size()) {
        a = recursiveCntDecodings(decoded, dp, index + 2);
      }
      if (curr_val != 0) {
        b = recursiveCntDecodings(decoded, dp, index + 1);
      }
      dp[index] = a + b;
    }
    return dp[index];
  }

public:
  int numDecodings(string s) {
    vector<int> dp(s.size(), 0); // used for storing intermediate result
    return recursiveCntDecodings(s, dp, 0);
  }
};

int main(void) {

  string str = "111111111111111111111111111111111111111111111";
  Solution sol;
  cout << "decoding number: " << sol.numDecodings(str) << endl;
  return 0;
}
