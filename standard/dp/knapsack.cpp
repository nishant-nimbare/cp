#include<iostream>
#include<vector>

using namespace std;




int main(){

    int capacity= 10;
    int itemSize  = 10;
    vector<int> values = {6, 3, 8, 1, 7, 3, 8, 6, 5, 6};
    vector<int> weights = {1, 2, 10, 6, 5, 1, 7, 4, 10, 4};

    int dp[capacity+1][itemSize+1];

    // initialize
    for(int i=0; i<=capacity; i++) dp[i][0] = 0;

    for(int j=0; j<=itemSize; j++) dp[0][j] = 0;


    // values and weights are 0 indexed
    // but dp table items are 1 indexed

    for(int i=1; i<=itemSize; i++){
        for(int c=1; c<=capacity; c++){

            dp[c][i] = dp[c][i-1];

            if( ( c  >= weights[i-1] ) && (dp[ c - weights[i-1] ][i-1] + values[i-1]) > dp[c][i] ){
                dp[c][i] = dp[ c - weights[i-1] ][i-1] + values[i-1];
            }

            // cout<<dp[c][i]<<" ";
        }
        // cout<<"\n";
    }


    cout<<dp[capacity][itemSize]<<"\n";

    return 0; 
}
