#include <iostream>
#include <vector>

using std::vector;

// done

vector<int> optimal_summands(int n) {
  vector<int> summands;
  //write your code here
  if(n>0){
    summands.push_back(1);
    n-=1;
  }

  while((n > 0) && ( summands.back()+1 <= n ) ){
    summands.push_back(summands.back()+1);
    n-=summands.back();
  }

  if(n>0){
    summands.back() += n; 
  }

  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
