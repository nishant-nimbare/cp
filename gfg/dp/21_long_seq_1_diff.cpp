#include <bits/stdc++.h>

#define DEBUG true

#ifdef DEBUG
#define dout cout
#else
#define dout 0 && cout
#endif

using namespace std;



int lnSeq1D(vector<int> arr){

  if(arr.empty()) return 0;

  vector<int> dp(arr.size(), 1);

  /* dp[0] = arr[0]; */

  int global_max = 1;


  for(int j=1; j<arr.size(); j++){
    int local_max = 1;

    for(int i=0; i<j; i++){

      if( abs(arr[i]-arr[j]) == 1 ){ 
        local_max = max(dp[i]+1, local_max);
      }
    }

    dp[j]=local_max;
    global_max = max(local_max, global_max);
  }

  for(int t:dp) cout<<t<<" ";

  cout<<endl;

  return global_max;

}

int main(int argc, char const *argv[]){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cout<<lnSeq1D(vector<int>{1, 2, 3, 2, 3, 7, 2, 1})<<"\n";
}
