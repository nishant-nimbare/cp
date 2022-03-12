#include <bits/stdc++.h>

#define DEBUG true

#ifdef DEBUG
#define dout cout
#else
#define dout 0 && cout
#endif

#define PS <<" - "<<
#define PG <<"  "<<
#define PE <<endl

#define F first
#define S second

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

void printVec(string name,vector<int> a){ dout<<name<<" : "; for(auto x:a) dout<<x<<" "; dout<<endl;}

// printBT for printing tree horizontally

int inf = 100000000;

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vi dp(n+1);

    dp[0]=0;

    for(int i=1;i<=n; i++){

        if(i<10) dp[i] = 1;
        else{

            int k=i, best=inf;
            while(k>0){
                int d=k%10;
                if(d>0) best = min(best, dp[i-d]+1);
                k=k/10;
            }
            dp[i] = best;
        }
    }
    cout<<dp[n];

    // printVec("dp",dp);

    return 0;
}
