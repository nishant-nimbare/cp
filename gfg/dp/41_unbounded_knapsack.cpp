#include <bits/stdc++.h>

#define DEBUG true

#ifdef DEBUG
#define dout cout
#else
#define dout 0 && cout
#endif

using namespace std;

int start(vector<int> V, vector<int> W, int target) {

  // elements can be repeated and the problem actually becomes simpler

  vector<int> dp(target+1,0);
  dp[0] = 0;

  for(int i=0; i<=target; i++){

    for(int e=0; e<V.size(); e++){

      if(i+W[e] <= target ){
        dp[i+W[e]] = max( dp[i]+V[e], dp[i+W[e]] ); 
      }
    }

  }
  return dp[target];
}

int main(int argc, char const* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> W = {1, 3, 4, 5}, V = {10, 40, 50, 70};
    int target = 8;
    cout << start(V, W, target) << endl;
    return 0;

}
