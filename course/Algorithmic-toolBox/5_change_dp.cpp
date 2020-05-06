#include <iostream>
#include <algorithm>
#define usi unsigned short int
using namespace std;

usi mhash[1001];

usi mmin(usi a, usi b, usi c){

  return std::min(a,std::min(b,c));

}

int get_change(int m) {

  // coins are of 1, 3, 4 

  mhash[0] = 0;
  mhash[1] = mhash[3] = mhash[4] = 1;
  mhash[2] = 2;

  for( int i=5; i<=m; i++){

    mhash[i] = mmin(
                  (mhash[i-1]+1),
                  (mhash[i-3]+1),
                  (mhash[i-4]+1)
              );
  
  }

  return (int)mhash[m];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
