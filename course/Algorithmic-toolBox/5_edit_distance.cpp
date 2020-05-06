#include <iostream>
#include <string>
#include <algorithm>

using std::string;
using std::min;


int mmin(int a, int b, int c){
  return min(a, min(b,c));
}

int edit_distance(const string &str1, const string &str2) {
  //write your code here
  size_t l1 = str1.length();
  size_t l2 = str2.length();

  int table[l1+1][l2+1];


  for(int i=0;i<=l1;i++) table[i][0] = i;
  for(int i=0;i<=l2;i++) table[0][i] = i;


  for(int i=1;i<=l1;i++){
    for(int j=1;j<=l2;j++){
      
      if( str1[i-1] == str2[j-1] ) table[i][j] = table[i-1][j-1]; //same chars
      else {
          table[i][j] = mmin(
              (table[i-1][j] + 1),
              (table[i][j-1] + 1),
              (table[i-1][j-1] + 1) // change
          );
      }
    }
  }
  
  return table[l1][l2];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
