#include <bits/stdc++.h>

#define DEBUG true

#ifdef DEBUG
#define dout cout
#else
#define dout 0 && cout
#endif

using namespace std;


int lcs(string str1, string str2, string str3){
	size_t s1=str1.size(), s2=str2.size(),s3=str3.size();
	unsigned int dp[s1+1][s2+1][s3+1];

	for(int i=0;i<=s1;i++){

		for(int j=0;j<=s2;j++){

			for(int k=0;k<=s3;k++){

				if(i==0 || j==0 || k==0) dp[i][j][k] = 0;

				else if( str1[i-1] == str2[j-1] && str3[k-1] == str2[j-1] ) dp[i][j][k] =1+dp[i-1][j-1][k-1];  
				else 
					dp[i][j][k]  = max(dp[i][j][k-1], max(dp[i-1][j][k] ,dp[i][j-1][k] )); 
			}		
		}
	}
	return dp[s1][s2][s3];

}

int main(int argc, char const *argv[]) {
	string str1="AGGT12", str2="12TXAYB", str3="12XBA";

	cout<<lcs(str1, str2, str3)<<endl;
	return 0;
}
