#include <bits/stdc++.h>

// #define DEBUG true

#ifdef DEBUG
#define dout cout
#else
#define dout 0 && cout
#endif

#define lli long long int

using namespace std;

const int MAXN = 3*100000 +1;

vector<int> arr;
map< pair<int, bool> , lli > dp;

lli go(int i, bool turn){

    if(i>=arr.size()) return 0;

    if(dp[{ i,turn }] > 0 ) return dp[{ i,turn }];

    lli best = go(i+1, turn); // not considering current element

    if(turn){
        // odd position add
        best = max(best, ( go(i+1, false) + arr[i] ));
    }else{
        // even position substract
        best = max(best, ( go(i+1, true) - arr[i] ));
    }


    dp[{ i,turn }] = best;
    
    dout<<" - "<<i<<" "<<turn<<" = "<<dp[{ i,turn }]<<endl;

    return dp[{ i,turn }];
}

int main(int argc, char const *argv[]){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int t;
	cin>> t;
	
	while(t--){
		int n,q;
		cin >> n>>q;

        arr.clear();
        arr.resize(n);

        dp.clear();

        for (int i = 0; i < n; i++) {
			cin >>arr[i];
		} 

        cout<< go(0,true) <<endl;

	}

	return 0;
}