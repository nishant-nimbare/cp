#include <bits/stdc++.h>

#define DEBUG true

#ifdef DEBUG
#define dout cout
#else
#define dout 0 && cout
#endif

using namespace std;



int msIns(vector<int> arr){

  if(arr.empty()) return 0;

  vector<int> dp(arr.size(), 0);

  dp[0] = arr[0];

  int global_max = arr[0];


  for(int j=1; j<arr.size(); j++){
    int local_max = arr[j];

    for(int i=0; i<j; i++){

      if(arr[i]<arr[j]){  // strictly increasing : < ; decreasing : >
        local_max = max(dp[i]+arr[j], local_max);
      }
    }

    dp[j]=local_max;
    global_max = max(local_max, global_max);
  }

  return global_max;
}

int main(int argc, char const *argv[]){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cout<<msIns(vector<int>{1, 101, 2, 3, 100, 4, 5})<<"\n";
}
