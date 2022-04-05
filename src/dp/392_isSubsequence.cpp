// 392. Is Subsequence
// A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters 
// without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.length()==0){
            return true;
        }
        
        int i=0;
        int j=0;        
        while(t.length()-j >= s.length()-i) {
            if (s[i]==t[j]) {
                i++;
                j++;
                if (i==s.length()) {
                    return true;
                }
            } else {
                j++;
            }
        }
        // cout << "i:" << i << endl;
        // cout << "j:" << j << endl;
        return false;
        
    }
};