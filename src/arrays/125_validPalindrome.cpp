// 125. Valid Palindrome

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;


class Solution {
public:
    bool isPalindrome(string s) {
        int i=0;
        int j=s.length()-1;
        
        transform(s.begin(), s.end(), s.begin(), ::tolower); 
        //cout << s << endl;
        while(i<j) {
            while(i<s.length()-1 && !((s[i]>='0' && s[i]<='9') || (s[i]>='a' && s[i]<='z'))) {
                i++;
            }
            while(j>0 && !((s[j]>='0' && s[j]<='9') || (s[j]>='a' && s[j]<='z'))) {
                j--;
            }
            
            if (i==j) {
                return true;
            }
            
            if (!((s[i]>='0' && s[i]<='9') || (s[i]>='a' && s[i]<='z')) && !((s[j]>='0' && s[j]<='9') || (s[j]>='a' && s[j]<='z'))) {
                // cout << "i:" << i << endl;
                // cout << "j:" << j << endl;
                // cout << "end reached" << endl;
                break;
            }
            
                
            if (s[i]!=s[j]) {
                return false;
            } else {
                i++;
                j--;
            }
            
        }
        return true;
        
    }
};
