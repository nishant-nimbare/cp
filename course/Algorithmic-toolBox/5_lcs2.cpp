#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

int lcs2(vector<int> &a, vector<int> &b) {
  //write your code here
  size_t l1 = a.size();
  size_t l2 = b.size();

  int table[l1+1][l2+1];


  for(int i=0;i<=l1;i++) table[i][0] = 0;
  for(int i=0;i<=l2;i++) table[0][i] = 0;


  for(int i=1;i<=l1;i++){
    for(int j=1;j<=l2;j++){
      
      if( a[i-1] == b[j-1] ) table[i][j] = table[i-1][j-1]+1; //same chars
      else {
          table[i][j] = std::max(
              (table[i-1][j]),
              (table[i][j-1])
          );
      }
    }
  }
  
  return table[l1][l2];
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}
