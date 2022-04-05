/*
 * 575. Valid Anagram - Easy
 * */

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        //#1 O(n^2) solution
//         if (s.length() != t.length()) {
//             return false;
//         }
        
//         vector<bool> matched(s.length(), false);
//         int cnt = 0;
//         for (int i=0; i<s.length(); i++) {
//             for (int j=0; j<t.length(); j++) {
//                 if (s[i]==t[j] && !matched[j]) {
//                     matched[j] = true;
//                     cnt++;
//                     break;
//                 }
//             }
//         }
        
//         if (cnt == s.length()) {
//             return true;
//         }
//         return false;
        //#2 O(nlogn) solution
        
//         sort(s.begin(), s.end());
//         sort(t.begin(), t.end());
        
//         if (s==t) {
//             return true;
//         }
//         return false;
        
        // O(n) solution
        
//         unordered_map<char, int> umap;
//         // unordered_map<char, int> umap2;
        
//         for (int i=0; i<s.length(); i++) {
//             umap[s[i]]++;
//         }
        
//         for (int i=0; i<t.length(); i++) {
//             umap[t[i]]--;
//         }
        
//         for (auto i : umap) {
//             if (i.second!=0) {
//                 return false;
//             }
//         }
//         return true;
        
        vector<int> vMap(128,0);
        
        for (int i=0; i<s.length(); i++) {
            vMap[s[i]]++;
        }
        
        for (int i=0; i<t.length(); i++) {
            vMap[t[i]]--;
        }
        
        for (int i=0; i<vMap.size(); i++) {
            if (vMap[i]!=0) {
                return false;
            }
        }
        return true;
        
    }
};
