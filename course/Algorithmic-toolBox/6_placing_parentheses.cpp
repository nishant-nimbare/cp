#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#define ll long long

using std::vector;
using std::string;
using std::max;
using std::min;
using std::cout;

ll MAX[30][30];
ll MIN[30][30];



long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {

    cout<<" ----------- Failed at "<<a<<b<<op<<"\n";
    assert(0);
  }
}


ll mmax(ll axl, ll axr, ll inl, ll inr, char op){

  return max(
    max( eval(axl,axr,op), eval(axl,inr,op) ),
    max( eval(inl,axr,op), eval(inl,inr,op) )
  );

}

ll mmin(ll axl, ll axr, ll inl, ll inr, char op){

  return min(
    min( eval(axl,axr,op), eval(axl,inr,op)),
    min( eval(inl,axr,op), eval(inl,inr,op))
  );

}



long long get_maximum_value(const string &exp) {
  //write your code here

  for(int s=0; s<exp.length(); s+=2){
    for(int i=0; i<exp.length();i+=2){
        int j = i+s;
        if(j >= exp.length() ) break;
        if(i==j){
          MAX[i][j] = MIN[i][j] = (exp[i]-'0');
          continue;
        }

        ll curMax ;
        ll curMin ;
        bool f = false;

        // cout<<" i:"<<i<<" j:"<<j<<" subStr: "<<exp.substr(i,s+1)<<" ";

        //try splitting at every operator in between
        for(int m=i; m<=j-2; m+=2){
          ll maxl = MAX[i][m];
          ll maxr = MAX[m+2][j];
          ll minl = MIN[i][m];
          ll minr = MIN[m+2][j];

          char op = exp[m+1];

          if(!f){
            curMax = mmax(maxl, maxr, minl, minr, op); 
          }else
            curMax = max(curMax, mmax(maxl, maxr, minl, minr, op));


          if(!f){
            curMin = mmin(maxl, maxr, minl, minr, op);
          }else
            curMin = min(curMin, mmin(maxl, maxr, minl, minr, op));

          f=true;                      
        }

        MAX[i][j] = curMax;
        MIN[i][j] = curMin;

        // cout<<" max="<<curMax<<" min="<<curMin<<" \n";
    }
  }

  return MAX[0][exp.length()-1];
}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
