#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using std::vector;
using std::stack;


struct op{
  unsigned int min_ways;
  char factor;
  // op(unsigned int mw, char f){
  //   min_ways=mw;
  //   factor = f;
  // }
};


struct op mhash[1000000];

vector<int> dp(int n){


// build the hash
  op ini = {0,'1'};
  mhash[0] = mhash[1] = ini;
  
  for( int i =2; i<=n; i++){
   
    unsigned int a = -1;
    char f;


    if( ( i%3==0 ) && ( (a==-1) || ((mhash[i/3].min_ways + 1)<a) ) ){
    
      a = mhash[i/3].min_ways + 1;
      f = '3';

    } 


    if( ( i%2==0 ) && ( (a==-1) || ((mhash[i/2].min_ways + 1)<a) ) ){

      a=mhash[i/2].min_ways + 1;
      f='2';
    } 
    

    if( (a==-1) || ((mhash[i-1].min_ways + 1)<a) ){

      a = mhash[i-1].min_ways + 1;
      f='1';
    
    }

    op cur={ a, f };
    mhash[i]=cur;
  
  }


  stack<int> ans;
  int i=n;
  ans.push(n);

  while(i!=1){
    switch (mhash[i].factor){

    case '1':
      i-=1;
      break;

    case '2':
      i /= 2;
      break;

    case '3':
      i /= 3 ;
      break;
    
    }

    ans.push(i);
  }


  vector<int> res;
  while(!ans.empty()){
    res.push_back(ans.top());
    ans.pop();
  }

  
  return res;

}

vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n /= 3;
    } else if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = dp(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
