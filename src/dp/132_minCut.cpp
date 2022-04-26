/*
 * 132_minCut.cpp
 *	Palindrome Partitioning II
 *
 *	dp[start_i] - holds the minimum cut number.
 *	if dp>=0, we already calculated the value, no need to recalculate.
 *
 *  Created on: Apr 25, 2022
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
	int check_palindrome(string &s, int s_i, int e_i)
	{
		while (s_i < e_i)
		{
			if (s[s_i] != s[e_i])
			{
				return 0;
			}
			s_i++;
			e_i--;
		}
		return 1;
	}
	int recursive_check(string &s, int start_i, vector<int> &dp)
	{
		if (start_i >= s.size())
		{
			return 0;
		}

		if (dp[start_i] >= 0)
		{
			return dp[start_i];
		}
		int min_val = INT_MAX;
		int temp;
		for (int i = start_i; i < s.size(); i++)
		{
			if (check_palindrome(s, start_i, i))
			{
				temp = recursive_check(s, i + 1, dp);
				if (min_val > temp + 1)
				{
					min_val = temp + 1;
				}
			}
		}
		dp[start_i] = min_val;
		return min_val;
	}

  public:
	int minCut(string s)
	{
		vector<int> dp(s.size(), -1);
		return recursive_check(s, 0, dp) - 1;
	}
};

int main()
{
	Solution sol;
	cout << sol.minCut(
				"fiefhgdcdcgfeibggchibffahiededbbegegdfibdbfdadfbdbceaadeceeefi"
				"heibahgececggaehbdcgebaigfacifhdbecbebfhiefchaaheiichgdbheacfb"
				"hfiaffaecicbegdgeiaiccghggdfggbebdaefcagihbdhhigdgbghbahhhdagb"
				"daefeccfiaifffcfehfcdiiieibadcedibbedgfegibefagfccahfcbegdfdhh"
				"dgfhgbchiaieehdgdabhidhfeecgfiibediiafacagigbhchcdhbaigdcedgge"
				"hhgdhedaebchcafcdehcffdiagcafcgiidhdhedgaaegdchibhdaegdfdaiiid"
				"cihifbfidechicighbcbgibadbabieaafgeagfhebfaheaeeibagdfhadifafg"
				"hbfihehgcgggffgbfccgafigieadfehieafaehaggeeaaaehggffccddchibeg"
				"fhdfafhadgeieggiigacbfgcagigbhbhefcadafhafdiegahbhccidbeeagcge"
				"behheebfaechceefdiafgeddhdfcadfdafbhiifigcbddahbabbeedidhaieag"
				"heihhgffbfbiacgdaifbedaegbhigghfeiahcdieghhdabdggfcgbafgibiifd"
				"eefcbegcfcdihaeacihgdchihdadifeifdgecbchgdgdcifedacfddhhbcagai"
				"cbebbiadgbddcbagbafeadhddaeebdgdebafabghcabdhdgieiahggddigefdd"
				"ccfccibifgbfcdccghgceigdfdbghdihechfabhbacifgbiiiihcgifhdbhfca"
				"iefhccibebcahidachfabicbdabibiachahggffiibbgchbidfbbhfcicfafgc"
				"agaaadbacddfiigdiiffhbbehaaacidggfbhgeaghigihggfcdcidbfccahhga"
				"ffiibbhidhdacacdfebedbiacaidaachegffaiiegeabfdgdcgdacfcfhdcbfi"
				"aaifgfaciacfghagceaaebhhibbieehhcbiggabefbeigcbhbcidbfhfcgdddg"
				"dffghidbbbfbdhcgabaagddcebaechbbiegeiggbabdhgghciheabdibefdfgh"
				"bfbfebidhicdhbeghebeddgfdfhefebiiebdchifbcbahaddhbfafbbcebiiga"
				"dhgcfbebgbebhfddgdeehhgdegaeedfadegfeihcgeefbbagbbacbgggciehdh"
				"iggcgaaicceeaefgcehfhfdciaghcbbgdihbhecfbgffefhgiefgeiggcebgaa"
				"cefidghdfdhiabgibchdicdehahbibeddegfciaeaffgbefbbeihbafbagaged"
				"gbdadfdggfeaebaidchgdbcifhahgfdcehbahhdggcdggceiabhhafghegfdie"
				"gbcadgaecdcdddfhicabdfhbdiiceiegiedecdifhbhhfhgdbhibbdgafhgdch"
				"eefdhifgddchadbdggiidhbhegbdfdidhhfbehibiaacdfbiagcbheabaaebfe"
				"aeafbgigiefeaeheabifgcfibiddadicheahgbfhbhddaheghddceedigddhch"
				"ecaghdegigbegcbfgbggdgbbigegffhcfcbbebdchffhddbfhhfgegggibhafi"
				"ebcfgeaeehgdgbccbfghagfdbdfcbcigbigaccecfehcffahiafgabfcaefbgh"
				"ccieehhhiighcfeabffggfchfdgcfhadgidabdceediefdccceidcfbfiiaide"
				"chhbhdccccaigeegcaicabbifigcghcefaafaefd")
		 << endl;
	return 0;
}
