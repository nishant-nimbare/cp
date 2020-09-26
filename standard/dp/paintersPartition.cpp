#include <bits/stdc++.h>
using namespace std;

const int  MAXB = 1000;

vector<int> boards;
int dp[MAXB][MAXB]={};

int go(int i, int k){
	

	if( i==boards.size() || k==0) return 0;

	if(dp[i][k] != 0) return dp[i][k]; 

	
	if(k==1){
		// only 1 painter remaining
		// he does all the remaining boards
		int sum=0;
		for(int t=i; t<boards.size(); t++){
			sum+=boards[t];
		}
		dp[i][k]=sum;	
		cout<<" - "<<i<<" "<<k<<" = "<<dp[i][k]<<endl;
		return sum;
	}

	int sum=0,best=INT32_MAX;
	for(int t=i; t<boards.size(); t++){
		sum+=boards[t];
		best = min(best, max(sum, go(t+1, k-1)));
	}
	dp[i][k]=best;		
	cout<<" - "<<i<<" "<<k<<" = "<<dp[i][k]<<endl;
	return best;

}


int main(){
  	int n,k;
	cin>>n>>k;
	boards.clear();
	boards.resize(n);

	for(int i=0;i<n;i++){
		cin>>boards[i];
	}

	cout<<go(0,k)<<endl;
}
