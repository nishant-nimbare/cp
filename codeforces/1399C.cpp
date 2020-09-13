#include <bits/stdc++.h>

// #define DEBUG true

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
	cin>> t;
	
	while(t--){
        dout<<"---------------------"<<endl;

		int n;
		cin >> n;

        vector<int> cnt(n+1, 0);

        for (int i = 0; i < n; i++) {

			int a; cin>>a;
            cnt[a] +=1;
		} 


        for (int i = 0; i <= n; i++) {
            dout<<i<<" -> "<<cnt[i]<<endl;
		} 


        // iterate over all possible s
        int best = 0;

        for(int s = 2; s<=2*n; s++){
            int cur =0;
            for(int k=1; 2*k<=s; k++){
                if( 2*k == s ) cur += cnt[k]/2;
                else if((s-k)<=n)
                    cur += min(cnt[k],cnt[s-k]);

                dout<<" - - cur "<<cur<<endl; 
            }

            best = max(best, cur);
            dout<<" - s = "<<s<<"  best ="<<best<<endl;
        }

        cout<<best<<endl;
	}

	return 0;
}