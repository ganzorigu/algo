/*
 * 20. Valid Parentheses
 * */

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>
#include <unordered_map>


// O(n) solution
using namespace std;

class Solution {
public:
  // bool isValid(string s) {
	// 	if (s.size()==0) {
	// 		return true;
	// 	}
		
	// 	if (s.find("()")!=string::npos) {
	// 		int index = s.find("()");
	// 		s.replace(index, 2, "");
	// 		return isValid(s);
	// 	} else if (s.find("{}")!=string::npos) {
	// 		int index = s.find("{}");
	// 		s.replace(index, 2, "");
	// 		return isValid(s);
	// 	} else if (s.find("[]")!=string::npos) {
	// 		int index = s.find("[]");
	// 		s.replace(index, 2, "");
	// 		return isValid(s);
	// 	} else {
	// 		return false;
	// 	}
	// }
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> umap = {
                                          { '{', '}' },
                                          { '(', ')' },
                                          { '[', ']' }
                                                        };
        for (int i=0; i<s.length(); i++) {
            if (umap.find(s[i]) != umap.end()) {
                st.push(s[i]);
            } else {
                if (st.empty()) {
                    return false;
                }
                if (umap[st.top()]!=s[i]) {
                    return false;
                } else {
                    st.pop();
                }
            }            
        }
        if (st.size()>0) {
            return false;
        }
        return true;
    }
};


int main() {
  Solution sol;
  cout << "Valid:" << sol.isValid("()}") << endl;
}
