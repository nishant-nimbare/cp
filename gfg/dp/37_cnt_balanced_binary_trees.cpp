#include <bits/stdc++.h>

// #define DEBUG true

#ifdef DEBUG
#define dout cout
#else
#define dout 0 && cout
#endif

using namespace std;
// https://practice.geeksforgeeks.org/problems/bbt-counter/0    
// Given a height h, count and return the maximum number of balanced binary trees possible with height h. 
/***
 * 
 * A balanced binary tree is one in which for every node, the difference between heights of left and right subtree is not more than 1.
 * 
 *  possible child configurations for height h
 *  h-1, h-1
 *  h-2, h-1
 *  h-1, h-2
 * 
 *  dp[h] = 2*(dp[h-2]*dp[h-1]) + dp[h-1]*dp[h-1] 
 **/

int cntBBT(int height) {

    vector<int> dp(height+1);

    dp[0] = dp[1] = 1;

    for(int h=2; h<=height; h++){

        dp[h] = 2*(dp[h-2]*dp[h-1]) + dp[h-1]*dp[h-1];
        
    }
    return dp[height];
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int height=70;

    cout << cntBBT(height) << endl;

    return 0;
}