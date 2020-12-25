#include <bits/stdc++.h>

#define DEBUG true

#ifdef DEBUG
#define dout cout
#else
#define dout 0 && cout
#endif

using namespace std;

/* Given an array of integers and a number k. We can pair two number of array if difference between them is strictly less than k. 
 * The task is to find maximum possible sum of disjoint pairs. Sum of P pairs is sum of all 2P numbers of pairs. */

int diffPairs(vector<int> arr, int k){

  if(arr.empty()) return 0;

  sort( arr.begin(), arr.end() );

  vector<int> dp(arr.size(), 0);

  dp[0] = 0;

  dp[1] = ((arr[1] - arr[0])<k)?(arr[1]+arr[0]):(0);

  int n= arr.size();



  for(int i=2; i<n; i++){

    dp[i] = dp[i-1];

    if( arr[i]- arr[i-1] < k){  // strictly increasing : < ; decreasing : >
      dp[i] = max(dp[i], dp[i-2]+arr[i]+arr[i-1]);
    }

  }


  return dp[n-1];
}

int main(int argc, char const *argv[]){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cout<<diffPairs(vector<int>{5, 15, 10, 300},12)<<"\n";
}
