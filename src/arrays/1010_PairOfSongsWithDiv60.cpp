// 1010. Pairs of Songs With Total Durations Divisible by 60
// You are given a list of songs where the ith song has a duration of time[i]
// seconds.

// Return the number of pairs of songs for which their total duration in seconds
// is divisible by 60. Formally, we want the number of indices i, j such that i
// < j with (time[i] + time[j]) % 60 == 0.

// Solution. need auxillary array to store the fractions.

#include <algorithm> // std::sort
#include <iostream>	 // std::cout
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
  public:
	int numPairsDivisibleBy60(vector<int> &time)
	{
		int numOfPairs = 0;
		vector<int> array60(60, 0);

		// all fractions are stored inside the array
		for (int i = 0; i < time.size(); i++)
		{
			array60[time[i] % 60]++;
		}

		// Possible pairs
		// 59 1
		// 29 31

		for (int i = 1; i < 30; i++)
		{
			numOfPairs += array60[i] * array60[array60.size() - i];
		}

		// if fraction is 30, 2 => 1, 3 => 2,

		for (int i = 1; i < array60[30]; i++)
		{
			numOfPairs += i;
		}

		for (int i = 1; i < array60[0]; i++)
		{
			numOfPairs += i;
		}

		return numOfPairs;
	}
};
