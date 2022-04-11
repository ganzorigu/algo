// 70. Climbing Stairs
// You are climbing a staircase. It takes n steps to reach the top.

// Each time you can either climb 1 or 2 steps. In how many distinct ways can
// you climb to the top?
#include <algorithm> // std::sort
#include <iostream>	 // std::cout
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
  public:
	int climbStairs(int n)
	{
		if (n == 1)
		{
			return 1;
		}

		long cnt = 0;
		int i = 1;

		// loop until 1x 2step till it is < n
		while (n - 2 * i > 0)
		{
			int rep;
			int numDigits;

			numDigits =
				n - i; // Example: if n=5, first time: 2111 = total 4 digits

			// calculating factorial is costly, it will overflow. so here trying
			// to refactor
			if (i > (n - 2 * i))
			{
				rep = n - i - i;
			}
			else
			{
				rep = i;
			}
			// temp = (numDigits!) / (i! * (numDigits-i)!)
			// rep is whichever highest;   (2*3*4*5) / ((2*3*4)*(1)) rep = 1;

			long temp = 1;
			int j = rep;
			int k = 2;

			while (j > 0)
			{
				temp = temp * numDigits;
				// at the same time multiplying, here it tries to divide, if it
				// is divisible; because number is so high that it will
				// overflow.
				if (k <= rep)
				{
					if (temp % k == 0)
					{
						temp = temp / k;
						k++;
					}
				}
				numDigits--;
				j--;
			}

			cnt = cnt + temp;
			i++;
		}

		cnt++; // all steps can be 1;
		if (n % 2 == 0)
		{ // all steps can be 2;
			cnt++;
		}

		return cnt;
	}
};
