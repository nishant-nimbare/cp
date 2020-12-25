#include <bits/stdc++.h>

#define PS <<" - "<<
#define PG <<"  "<<
#define PE <<endl

using namespace std;

int dp[1000][1000] ={};

int go(int n, int m, int k){

    if(n==0) return 1;

    if(m==0) return 0; 

    if(dp[n][m] == -1){
        // take 0 to k of mth tile

        int cur =0;
        for(int i=0; i<=k; i++){
            if(i <= n)
                cur  += go(n-i, m-1, k);
        }

        dp[n][m] = cur;
    }


    cout PS n PG m PG dp[n][m] PE;
    return dp[n][m];

}


int main(){


    memset(dp, -1, sizeof(dp));

    cout<<go(3,3,2) PE;
    return 0;
}