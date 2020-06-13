/*
 * @lc app=leetcode id=424 lang=cpp
 *
 * [424] Longest Repeating Character Replacement
 */
#include <bits/stdc++.h>
using namespace std;


// @lc code=start
class Solution {
public:
    int characterReplacement(string s, int k) {

        unordered_map<char,int> freq;
        int ansLen=0, l=0, r=0, curk=0, ans=0;
        char curMax = s[0];

        for(r=0; r<s.size(); r++){

            freq[s[r]] +=1;

            if((r-l+1) <= freq[curMax]+k) {
                ans = max(ans, r-l+1);
            }

            if( curMax != s[r] ){

                if(freq[curMax] <= freq[s[r]]){
                    curMax = s[r];
                }

                while( (r-l+1) > freq[curMax]+k ){
                    freq[s[l]] -= 1;    
                    l++;
                }

                if((r-l+1) <= freq[curMax]+k) {
                    ans = max(ans, r-l+1);
                }


            }

        }

        return ans;

    }
};
// @lc code=end

