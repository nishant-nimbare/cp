#include <bits/stdc++.h>

#define DEBUG true

#ifdef DEBUG
#define dout cout
#else
#define dout 0 && cout
#endif

using namespace std;

//Given a fence with n posts and k colors, find out the number of ways of painting the fence such that at most 2 adjacent posts have the same color. Since answer can be large return it modulo 10^9 + 7.

long dp[100][100]={};
long long mod = 1000000007;

long go(int e, int f) {


  if( e<0 || f<=0 ){
    return 0;
  }

  if( e==1 ) return f;


  if(dp[e][f] == 0){
    // try every floor
    //
    dp[e][f] = INT_MAX;
    for(int k= 1; k<=f; k++){

      dp[e][f] = min( dp[e][f],   1 + max(

            go(e-1, k-1), // egg breaks from kth floor

            go(e, f-k)   //egg doesn't break
            )
          );

    }
  }

  //dout<<" - "<<i<<" "<<k<<" "<<dp[i]<<endl;
  return dp[e][f];

}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n=2, f=36;
  cout<<go(n,f)<<endl;

  return 0;
}
