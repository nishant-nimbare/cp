#include <bits/stdc++.h>

#define DEBUG true

#ifdef DEBUG
#define dout cout
#else
#define dout 0 && cout
#endif

using namespace std;


int main(int argc, char const *argv[]){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int t;
	// std::fstream myfile("./input.txt", std::ios_base::in);

	cin>> t;
	
	while(t--){
		int n;
		cin >> n;

        vector<int> a(n), b(n), c(n), ans(n,-1);
        
        for (int i = 0; i < n; i++) cin>>a[i];
        for (int i = 0; i < n; i++) cin>>b[i];
        for (int i = 0; i < n; i++) cin>>c[i];


        // ans[0] = a[0];

        for (int i = 1; i < n-1; i++){
            
            if( a[i-1] == a[i] ) a[i]=b[i];

            if( a[i-1] == a[i] ) a[i]=c[i];

        }

        if( a[n-1]==a[n-2] || a[n-1] ==a[0] ) {
           
            a[n-1] = b[n-1];
       
        }


        if( a[n-1]==a[n-2] || a[n-1] ==a[0] ) {
           
            a[n-1] = c[n-1];
       
        }
        
        for (int i = 0; i < n; i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;

	}

	return 0;
}