#include <bits/stdc++.h>

#define DEBUG true

#ifdef DEBUG
#define dout cout
#else
#define dout 0 && cout
#endif

#define SUM_MAX 1000
#define ARR_MAX 100

using namespace std;


int dp[ARR_MAX][SUM_MAX];

int sumLessK(vector<int> arr, int k){

  // arr is 0 indexed but items are 1 indexed in dp
  //
  for(int i=0;i<=arr.size(); i++){ 

    for(int j=0;j<=k; j++){ 

      if(i==0 ||j==0) {
        dp[i][j] = 0;
        continue;
      }

      dp[i][j] = dp[i-1][j]; //not considering ith ele

      if(arr[i-1] <= j){

        dp[i][j] += dp[ i-1 ] [ j-arr[i-1] ] + 1; // considering ith ele and +1 for the element itself

      }
    }
  }

  return dp[arr.size()][k];
}

int ProductLessK(vector<int> arr, int k){

  // arr is 0 indexed but items are 1 indexed in dp
  //
  for(int i=0;i<=arr.size(); i++){ 

    for(int j=0;j<=k; j++){ 

      if(i==0 ||j==0) {
        dp[i][j] = 0;
        continue;
      }

      dp[i][j] = dp[i-1][j]; //not considering ith ele

      if(arr[i-1] <= j && arr[i-1]>0 ){

        dp[i][j] += dp[ i-1 ] [ j/arr[i-1] ] + 1; // considering ith ele and +1 for the element itself

      }
    }
  }

  return dp[arr.size()][k];
}


int main(int argc, char const *argv[]) {
  
  vector<int> arr ={1, 2, 3, 4};
  int k=10;

  /* cout<<sumLessK(arr, k)<<endl; */

  cout<<ProductLessK(arr, k)<<endl;
}
