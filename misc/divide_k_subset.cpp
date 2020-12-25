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

// https://www.geeksforgeeks.org/partition-of-a-set-into-k-subsets-with-equal-sum-using-bitmask-and-dp/

int dp[ (1<<15 ) ];

bool partitionK(vector<int> arr, int k){

    int n = arr.size();
    int target = 0;

    for(int t=0; t<n; t++) target += arr[t];

    cout PS " sum " PG target PE;

    if( (target % k ) != 0 ) return false; 

    target = target / k;
    cout PS " target " PG target PE;

    memset(dp, -1, sizeof(dp) );

    dp[ 0 ] = 0;

    for( int mask = 0; mask < (1 << n); mask++ ){

        // cout PS " - - - " PG mask PE;

        if( dp[mask] == -1 ){
            // invalid state : skip
            continue;
        } 


        if( dp[mask] == 0 ){
            cout PS " - 0 for mask " PG bitset<8> (mask) PE;
        }

        // check every element

        for( int e=0; e<n; e++){

            if( !(mask & ( 1<<e ) ) ) { // element not previously considered

                if( dp[mask] + arr[e] <= target ){
                    // element can be pushed

                    dp[mask | (1<<e) ] = (dp[mask] + arr[e]) % target;

                    // dout PS " - "  PG bitset<8> (mask)
                    /**
                     * dp[mask] + arr[n] == target
                     * 
                     * then dp[ mask | (1<<n ) ] will be 0
                     * 
                     * which means 1 set is over futher calculations will be to fill next set
                     * **/
                }
            }
        }
    }

    if( dp[ (1<< n) - 1] == 0) return true;

    return false;
}

int main(int argc, const char * argv[]){


    cout<< partitionK( vector<int> {2, 1, 4, 5, 3, 3}, 3) PE;
    return 0;
}