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

int dp[10000]={};

int wordBreak(string str, unordered_set<string> &mset, int i){

    if(i==-1) return 1;

    if(dp[i] == 0){

        for(int j=i; j>=0; j--){

            if(mset.count( str.substr(j, i - j +1) ) == 1 ){
                if(wordBreak(str, mset, j-1) == 1){
                    dp[i] = 1; break;
                }
            }
        }

        if(dp[i] == 0) dp[i] = -1;
    
    }

    return dp[i];
}

int main(){
    
    memset(dp, 0, sizeof(dp));

    unordered_set<string> mset {"mobile","samsung","sam","sung","man","mango", 
                           "icecream","and","go","i","like","ice","cream","k"};
    string str = "ilikelikeimangoiii";
    cout<<wordBreak(str, mset,str.size()-1) PE;

    for(int t=0; t<str.size(); t++ ) cout << dp[t] <<"  ";
    cout PE;

    return 0;
}