#include <bits/stdc++.h>

#define DEBUG true

#ifdef DEBUG
#define dout cout
#else
#define dout 0 && cout
#endif

using namespace std;

//Given a fence with n posts and k colors, find out the number of ways of painting the fence such that at most 2 adjacent posts have the same color. Since answer can be large return it modulo 10^9 + 7.

long long dp[100000]={};
long long mod = 1000000007;

long long go(int i, int &n, int &k) {


	if( i<0 || k==0 ){
		return 0;
	}

	if( i==0 ) return 1;

	//	if(i==1){return k;}


	if(dp[i] == 0){

		int curPossible = (i==n)?(k):(k-1);

		dp[i] = (curPossible* ( 

					go(i-1,n,k)%mod //only color i with some color 
					+ 
					go(i-2,n,k)%mod

				      ))%mod; // color i and i-1 with some color
	}

	//dout<<" - "<<i<<" "<<k<<" "<<dp[i]<<endl;
	return dp[i];

}


long long bottomUp(int n, int k){

	dp[1]=k;
	dp[2]=k*k;

	for(int i=3;i<=n;i++){
		dp[i] =( ((k-1)%mod)*(dp[i-1] + dp[i-2])%mod )%mod ;
	}
	return dp[n];
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n=40,k=79;
	cout<<go(n,n,k)<<endl;
	//cout<<bottomUp(n,k)<<endl;

	return 0;
}
