#include <bits/stdc++.h>

#define DEBUG true

#ifdef DEBUG
#define dout cout
#else
#define dout 0 && cout
#endif

using namespace std;


int lcs(string str1, string str2){
	size_t s1=str1.size(), s2=str2.size();
	unsigned int dp[s1+1][s2+1];

	for(int i=0;i<=s1;i++){

		for(int j=0;j<=s2;j++){

			if(i==0 || j==0) dp[i][j] = 0;

			else if( str1[i-1] == str2[j-1] ) dp[i][j]=1+dp[i-1][j-1];  
			else 
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]); 
		}		
	}
	return dp[s1][s2];

}

int main(int argc, char const *argv[]) {
	string str1="AGGTAB", str2="GXTXAYB";

	cout<<lcs(str1, str2)<<endl;
	return 0;
}
