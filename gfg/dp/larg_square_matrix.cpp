#include <bits/stdc++.h>

#define DEBUG true

#ifdef DEBUG
#define dout cout
#else
#define dout 0 && cout
#endif

using namespace std;

/* Given a binary matrix, find out the maximum size square sub-matrix with all 1s. */

int largSquare( vector<vector<int>> mat){

  int n = mat.size(), m=mat[0].size();

  vector<vector<int>> dp = mat;


  int global_max = 0;

  for(int i=0; i<n; i++){

    for(int j=0; j<m; j++){


      if( i==0 || j==0 ) {
        dp[i][j] = mat[i][j];
        continue;
      }

      if(mat[i][j] == 1){
        
        dp[i][j] = min(dp[i-1][j-1], min( dp[i-1][j], dp[i][j-1] )) + 1;
      }else{
        dp[i][j] = 0;

      }


      global_max = max( dp[i][j], global_max);
    
    }
  }


  for(vector<int> col:dp){
   
    for(int t: col)
      cout<<t<<" ";
  
    cout<<endl;
  }

  cout<<endl;

  return global_max;

}

int main(int argc, char const *argv[]){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  vector<vector<int>> mat =
  /* {{0, 1, 1, 0, 1}, */  
  /*   {1, 1, 0, 1, 0}, */  
  /*   {0, 1, 1, 1, 0}, */  
  /*   {1, 1, 1, 1, 0}, */  
  /*   {1, 1, 1, 1, 1}, */  
  /*   {0, 0, 0, 0, 0}}; */
   
    {

    {0,1,0,1,0,1},
    {1,0,1,0,1,0}, 
    {0,1,1,1,1,0}, 
    {0,0,1,1,1,0}, 
    {1,1,1,1,1,1}

  };

  cout<<largSquare(mat)<<"\n";
}
