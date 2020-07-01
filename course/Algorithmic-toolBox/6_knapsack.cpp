#include <iostream>
#include <vector>

using std::vector;
using std::cout;

const size_t MAX_N = 300;
const size_t MAX_W = 1000;

unsigned int table[ MAX_N + 1 ][ MAX_W + 1 ];

int dp(int W, const vector<int> &w){

/*  
  cout<<"    ";
  for(size_t j=0; j<=W; j++)cout<<j<<' ';
  cout<<"\n\n";
*/
  
  int k=0;
  for(size_t i=0; i<=w.size(); i++){

    // cout<<i<<" | ";

    for(size_t j=0; j<=W; j++){
      
      if( i==0 || j==0){
        table[i][j]=0;
        // cout<<table[i][j]<<' ';    
        continue;
      }

      if( j>= w[i-1]){
        table[i][j] = std::max( ( table[i-1][j-w[i-1]] + w[i-1] ), table[i-1][j] );
      }else{
        table[i][j] = table[i-1][j];
      }

      /*
      if( ( j >= w[i-1] ) && ( table[i-1][j-w[i-1]] + w[i-1] )>table[i][j] ){
        // k++;
        // cout<<" current item "<<w[i-1]<< " W "<<j<<" \n";
        table[i][j] = table[i-1][j-w[i-1]] + w[i-1];
        
      }
      */

      // cout<<table[i][j]<<' ';    
    }
    // cout<<'\n';
  }

  // cout<<"\n went inside if "<<k<<"\n";
  return table[w.size()][W];
}



int optimal_weight(int W, const vector<int> &w) {
  //write your code here
  int current_weight = 0;
  for (size_t i = 0; i < w.size(); ++i) {
    if (current_weight + w[i] <= W) {
      current_weight += w[i];
    }
  }
  return current_weight;
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << dp(W, w) << '\n';
}
