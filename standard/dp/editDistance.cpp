#include <bits/stdc++.h>

#define DEBUG true

#ifdef DEBUG
#define dout cout
#else
#define dout 0 && cout
#endif

using namespace std;


int editDist(string str, string tar){

    size_t tlen = tar.size(), slen = str.size();

    unsigned int dp[tlen+1][slen+1];

    for(int i=0; i<=tlen; i++){
        dp[i][0] = i;
    }

    for(int i=0; i<=slen; i++){
        dp[0][i] = i;
    }

    dout<<" starting \n";

    for (int i = 1; i <= tlen; i++){
        for (int j = 1; j <= slen; j++){

            dout<<" - "<<i<<" "<<j<<"\n";
            if( tar[i-1] == str[j-1] ){
                dp[i][j] = dp[i-1][j-1];
            }else{
                
                /***
                 * i-1, j-1 : replace
                 * i,   j-1 : delete
                 * i-1, j   : insert
                 * **/

                dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j] ) ) + 1; 

            }

        }
    }
    

    return dp[tlen][slen];
}


int main(int argc, char const *argv[]){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<editDist("cat", "car")<<"\n";
}