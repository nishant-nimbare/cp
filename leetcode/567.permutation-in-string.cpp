/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        unordered_map<char, int> tar, cur;

        if(s1.size()==0 || s2.size()==0 || s1.size()>s2.size()) return false;

        for(char c: s1){
            tar[c] += 1;
        }

        int tl=tar.size(), cl, l, r;
        cl=l=r=0;

        while(r<s1.size()){
            if(tar[s2[r]] > 0) {
                cur[s2[r]] +=1;

                if ( tar[s2[r]] == cur[s2[r]]) cl+=1;
            }
            r++;
        }

        if(cl == tl ) return true;

        while(r<s2.size()){
            
            if(tar[s2[r]] > 0) {
                cur[s2[r]] +=1;

                if ( tar[s2[r]] == cur[s2[r]]) cl+=1;
            }


            if(tar[s2[l]] > 0) {
                cur[s2[l]] -=1;
                if ( cur[s2[l]] == tar[s2[l]] - 1 ) cl-=1;
            }

            l++;

            if(cl == tl ) return true;
            
            r++;
        }
        
        return false;
    }
};
// @lc code=end

