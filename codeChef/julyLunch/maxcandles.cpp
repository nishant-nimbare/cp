#include <bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[]){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int t;
	cin>> t;
	
	while(t--){
		int n,m,x,y,a,b;
		cin>>n>>m>>x>>y;

        if(y<x){
            a=y;
            b=0;
        }else{
            a = x;
            b = y-x;
        }

        bool f = true;
        long long int ans=0;
        for(int row=0; row<n; row++){
            
            if(f){
                ans += (m+1)/2*a;
                ans += m/2*b;
            }else{
                ans += (m+1)/2*b;
                ans += m/2*a;
            }
            f = !f;
        }

        cout<<ans<<"\n";
	}

	return 0;
}