#include <bits/stdc++.h>

#define DEBUG true

#ifdef DEBUG
#define dout cout
#else
#define dout 0 && cout
#endif

using namespace std;


// LONGEST NON_DECREASING SUBSEQUENCE 

int lnds(vector<int> arr){

    if(arr.empty()) return 0;

    vector<int> dp(arr.size(), 1);
    int global_max = 1;


    for(int j=1; j<arr.size(); j++){
        int local_max = 1;

        for(int i=0; i<j; i++){

            if(arr[i]<=arr[j]){  // strictly increasing : < ; decreasing : >
                local_max = max(dp[i]+1, local_max);
            }
        }

        dp[j]=local_max;
        global_max = max(local_max, global_max);
    }

    return global_max;
}

int main(int argc, char const *argv[]){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<lnds(vector<int>{-1,3,4,5,2,2,2,2})<<"\n";
}