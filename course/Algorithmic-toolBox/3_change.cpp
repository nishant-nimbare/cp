#include <iostream>
using namespace std;

// done

int get_change(int m) {
  //write your code here
  
  short int denom[3]={10,5,1};
  int coins =0;
  int i =0;

  while(i<3){

    coins += m/denom[i];
    m = m%denom[i];
    i++;
  } 
  
  
  return coins;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
