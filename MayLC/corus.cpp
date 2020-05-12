#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int t;
	cin>> t;
	
	while(t--){
		int n,Q;
		cin >> n>>Q;

        int mhash[26];
        fill(mhash, mhash+26, 0);

        string str;
        cin>>str;

        for (int i = 0; i < n; i++) {            
            mhash[str[i]-'a'] +=1;
		}
        int c;
        for(int i=0; i<Q; i++){
            cin>>c;
            int ans=0;

            for(int v: mhash){
                ans+=max((v-c),0);
            }
            cout<<ans<<'\n';
        } 
	}

	return 0;
}