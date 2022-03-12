#include <bits/stdc++.h>

// #define DEBUG true

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

int dp[100000+1][1000+1];


int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,x,temp;
    cin>>n>>x;

    vi price(n+1), pages(n+1);

    // 1 indexing
    for(int t=1; t<=n; t++) {cin>>temp; price[t]=temp;}
    for(int t=1; t<=n; t++) {cin>>temp; pages[t]=temp;}


    // printVec("price",price);
    // printVec("pages",pages);

    for(int c=0; c<=x; c++){
        for(int i=0; i<=n; i++){

            if( i==0 || c==0){
                dp[c][i] = 0;
                // dout<<dp[c][i]<<" ";
                continue;
            }


            dp[c][i] = dp[c][i-1];

            if( (price[i]<=c) && ( (dp[c-price[i]][i-1] + pages[i]) > dp[c][i]) ) {
                dp[c][i] = dp[c-price[i]][i-1] + pages[i];
            }

            // dout<<dp[c][i]<<" ";
        }

        // dout<<endl;
    }

    // printVec("dp",dp);

    cout<<dp[x][n];
    return 0;
}
