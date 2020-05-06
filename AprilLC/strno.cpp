#include <bits/stdc++.h>
using namespace std;
// 1
// 5 2

int main(int argc, char const *argv[]){

	int t;
	cin>> t;

	while(t--){
		int x,k;
		cin >> x >>k;
		
		int factors=0;

		while(x%2==0){
			factors++;
			x=x/2;
		}

		if(factors >= k) {
			cout<<1<<'\n';
			continue;
		}

		for(int i=3; i<=sqrt(x); i+=2){
			while(x%i==0){
				x=x/i;
				factors++;
			}
		}
		
		if(x>2) factors++;


		if( factors < k ) cout<<0<<'\n'; //not possible
		if( factors >= k ) cout<<1<<'\n';
	}

	return 0;
}