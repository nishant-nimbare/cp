#include <bits/stdc++.h>

using namespace std;


int main(int argc, char const *argv[]){

	int t;
	cin>> t;
	
	while(t--){
		int n, k;
		cin >> n>>k;

        stringstream ss;
		 for (int i = 0; i < n; i++) {

			int a;
			cin>>a;
            if(a%k==0) ss<<'1';
            else ss<<'0';
		}

        string ans =ss.str(); 
        cout<<ans<<"\n"; 
	}

	return 0;
}