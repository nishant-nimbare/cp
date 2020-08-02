#include <bits/stdc++.h>

using namespace std;

vector<int> dp;

int main(int argc, char const *argv[]){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int t;
	cin>> t;
	
	while(t--){
		string str;
		cin >> str;

        if(str.size() == 1){
            cout<<0<<"\n";
            continue;
        }

        dp.resize(str.size(), 0);

        dp[1] = (str[0] != str[1] )?(1):(0);

        for (int i = 2; i < str.size(); i++) {

            if(str[i] != str[i-1]){
                //can form a pair
              dp[i] = max( dp[i-2]+1 , dp[i-1]);
            }else{
                // same chars
                dp[i] = dp[i-1];
            }    

        } 

        cout<<dp.back()<<"\n";
	}

	return 0;
}