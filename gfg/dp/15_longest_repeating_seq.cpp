#include <bits/stdc++.h>

#define DEBUG true

#ifdef DEBUG
#define dout cout
#else
#define dout 0 && cout
#endif

using namespace std;


/** 
  to find longest repeating subsequence
  we find the lcs of str with itself such that we increment comman chars iff they are on different indecies

 **/

int lrs(string str1){

  size_t s1=str1.size(); 
  unsigned int dp[s1+1][s1+1];

  for(int i=0;i<=s1;i++){

    for(int j=0;j<=s1;j++){

      if(i==0 || j==0) dp[i][j] = 0;

      else if( str1[i-1] == str1[j-1] && i!=j ) dp[i][j]=1+dp[i-1][j-1];  
      else 
        dp[i][j] = max(dp[i-1][j],dp[i][j-1]); 
    }		
  }
  return dp[s1][s1];

}

int main(int argc, char const *argv[]) {
  string str1="aabebcdd";

  cout<<lrs(str1)<<endl;
  return 0;
}
