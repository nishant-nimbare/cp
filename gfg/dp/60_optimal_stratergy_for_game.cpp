#include <bits/stdc++.h>

#define DEBUG true

#ifdef DEBUG
#define dout cout
#else
#define dout 0 && cout
#endif

#define PS <<" - "<<
#define PG <<"  "<<
#define PE <<endl

using namespace std;

//geeksforgeeks.org/optimal-strategy-for-a-game-dp-31/

int optimalStrategy(vector<int> coins){
    int n= coins.size();
    vector<vector<int>> dp (n);



    for(int i=0; i<n; i++){
        vector<int> temp (n,0);
        dp[i] = temp;
        dp[i][i] = coins[i];
    }

    for(int gap=0; gap<n; gap++){
        for(int i = 0; i<n-gap; i++){

            int x = 0;
            if( i+2 <= i+gap ) x = dp[i+2][i+gap];

            int y = 0;
            if( i+1 <= i+gap-1) y = dp[i+1][i+gap-1];

            int z = 0;
            if(i <= i+gap-2 ) z = dp[i][i+gap-2];

            dp[i][i+gap] = max(
                coins[i] + min(x, y),
                coins[i+gap] + min(y, 0)
            );
        }
    }

    return dp[0][n-1];
}

int main(int argc, char const *argv[]) {

    cout<<optimalStrategy(vector<int> {20, 30, 2, 2, 2, 10 }) << endl;
    return 0;
}
