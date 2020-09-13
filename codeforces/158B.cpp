#include <bits/stdc++.h>

using namespace std;


int main(int argc, char const *argv[]){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n;
	cin>> n;
	
    int hash[]= {0,0,0,0};


    for (int i = 0; i < n; i++) {
        int a; cin>>a;
        hash[a-1] += 1;
    } 

    int ans = 0;

    ans += hash[2];

    if(hash[2] <= hash[0]) hash[0] -= hash[2];

    ans += hash[1]/2;

    if( hash[1]%2==1){
        ans+=1;
        hash[0] -= min(hash[0], 2);
    }

    if( hash[0] > 0){
       ans += ((hash[0]-1) / 4)+1;
    }

    
    ans += hash[3];

    cout<<ans<<"\n";
	return 0;
}