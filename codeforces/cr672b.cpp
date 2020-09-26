#include <bits/stdc++.h>

// #define DEBUG true

#ifdef DEBUG
#define dout cout
#else
#define dout 0 && cout
#endif

using namespace std;


int mlog(int x){
    int res = 0;
    while(x>1){

        res +=1;
        x /= 2;
    }

    return res;
}

int main(int argc, char const *argv[]){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int t;
	cin>> t;
	
	while(t--){
		int n;
		cin >> n;

        unordered_map<int, int> setbit;

        int ans = 0;

        for (int i = 0; i < n; i++) {

			int a;
			cin >>a;

            int b = mlog(a);
            dout<<a<<" - "<<b<<endl;
            ans += setbit[b];

            setbit[b] += 1;

		} 

        cout<<ans<<endl;
	}

	return 0;
}