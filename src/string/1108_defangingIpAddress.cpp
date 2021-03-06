// 1108. Defanging an IP Address
// Given a valid (IPv4) IP address, return a defanged version of that IP
// address.

// A defanged IP address replaces every period "." with "[.]".

#include <algorithm> // std::sort
#include <iostream>	 // std::cout
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
  public:
	string defangIPaddr(string address)
	{
		string ans;

		for (int i = 0; i < address.length(); i++)
		{
			if (address[i] == '.')
			{
				ans += "[.]";
			}
			else
			{
				ans.push_back(address[i]);
			}
		}
		return ans;
	}
};
