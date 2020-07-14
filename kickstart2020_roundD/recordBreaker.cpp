#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int tests;

	cin>> tests;
	
	for( int t = 1; t <= tests; t++) {
		int n;
		cin >> n;

        vector<int> arr;
		for (int i = 0; i < n; i++) {
			int a; cin>>a;
            arr.push_back(a);
		} 


        int mmax = arr[0], ans = 0;

        for(int i =0; i<n; i++){
            
            if( (i==0 || arr[i]>mmax) && ( i==(n-1) || arr[i]> arr[i+1] ) ){
                ans+=1;
                mmax = arr[i];
            }
        }

        cout<<"Case #"<<t<<": "<<ans<<"\n";

	}

	return 0;
}