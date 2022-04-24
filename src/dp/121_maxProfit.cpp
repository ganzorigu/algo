/*
 * 121_maxProfit.cpp
 * Best Time to buy and sell stock
 *  Created on: Apr 20, 2022
 *      Author: ganzo
 */
#include <algorithm> // std::sort
#include <iostream>	 // std::cout
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
  public:
  int maxProfit(vector<int>& prices) {
        int lsf = INT_MAX;
        int op = 0;
        int pist = 0;

        for(int i = 0; i < prices.size(); i++){
            if(prices[i] < lsf){
                lsf = prices[i];
            }
            pist = prices[i] - lsf;
            if(op < pist){
                op = pist;
            }
        }
        return op;
    }
};


int main()
{
	vector<int> arr = {7, 1, 5, 3, 6, 4};

	Solution sol;
	cout << "solution:" << sol.maxProfit(arr) << endl;
	return 0;
}
