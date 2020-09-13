#include <bits/stdc++.h>

#define DEBUG true

#ifdef DEBUG
#define dout cout
#else
#define dout 0 && cout
#endif


# define ull unsigned long long
# define ui unsigned int

using namespace std;



unordered_map<ull,ui> dp;

ui go(ull n){

    if(n<1) return UINT32_MAX;
    
    if(n==1) return 0;

    if(dp.count(n)) return dp[n];

    ui a=UINT32_MAX, b=UINT32_MAX, c=UINT32_MAX;
    
    if(n%2==0) a = go(n/2);
    
    if(n%3==0) b = go(2*n/3);

    if(n%5==0) c = go(4*n/5);


    ui best = min(min(a,b),c);

    if(best < UINT32_MAX){
        best+=1;
    }

    dp[n] = best;

    return best; 
}


int go1(ull n){

    int pow2=0, pow3=0, pow5=0;

    while(n%2==0){
        pow2++;
        n /= 2;
    }


    while(n%3==0){
        pow3++;
        n /= 3;
    }
    
    while(n%5==0){
        pow5++;
        n /= 5;
    }

    if(n==1) return pow2+ (2*pow3) + (3*pow5);

    return -1;
}



int main(int argc, char const *argv[]){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // dp.reserve(1024);
    // dp.max_load_factor(0.25);

	int t;
	cin>> t;
    // cout<<" max ull "<<UINT32_MAX<<endl;

	while(t--){
		ull n;
		cin >> n;

        int ans = go1(n);
        cout<<ans;
        cout << endl;

        // for(auto p : dp){
        //     cout<<p.first<<"->"<<p.second<<"  ";
        // }
        // cout<<endl;

	}

	return 0;
}