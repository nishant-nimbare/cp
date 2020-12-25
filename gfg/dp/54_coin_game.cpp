// https://www.geeksforgeeks.org/coin-game-winner-every-player-three-choices/

#include <bits/stdc++.h>

#define PS <<" - "<<
#define PG <<"  "<<
#define PE <<endl

using namespace std;


bool coinGame(int n, int x, int y){
    
    bool dp[10000] = { false };

    dp[0] = false; // 
    dp[1] = true; // A will pick last coin

    for(int i=2; i<=n; i++){

        /**
         * if A losses for i-1, i-x, i-y 
         * A will win for i, cause b will have i-1, i-x, i-y 
         *  
         * **/

        dp[i] = dp[i-1]; // pick 1 coin

        if( i>=x ) dp[i] = dp[i] & dp[i-x]; // pick x coin

        if( i>=y ) dp[i] = dp[i] & dp[i-y]; // pick y coin

        dp[i] = !dp[i];
    }


    return dp[n];
}

int main(int argc, char const *argv[]) {

    int  n=5, x=3, y=4;

    cout<< coinGame(n, x, y) PE;

    return 0;
}