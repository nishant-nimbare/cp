#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

//done

using namespace std;
// a < b ?
bool comp(string a, string b){

  // cout<<" -  comparing "<<a<<" "<<b<<"\n";

  int len = std::min( a.size(),b.size() );
  size_t c=0;
  
  while( c<len ){

    if( a[c] > b[c] ) return false;

    if( a[c] < b[c] ) return true;

    c++;
  }

  // cout<<" - almost same  \n";

  if(a.size() == b.size()){ //both the strings are same
    return false;
  }

  //one of the strings is over by now
  string rem = (a.size()>b.size())?(a):(b);

  c=len;

  while( c<rem.size() && rem[c-1] == rem[c] ) c++;

  if(c == rem.size() ) return false;

  if( rem[c-1] < rem[c]){
    // rem is a better string
    return (rem==b);
  }else{
    //rem is not better
    return (rem!=b);
  }

}


bool comp2(string a, string b){
  string ab = a+b;
  string ba = b+a;

  return (ba>ab);
}

string largest_number(vector<string> a) {
  //write your code here
  std::stringstream ret;

  while(a.size()>0){

    //get the next best number
    vector<string>::iterator best = a.begin();

    for( vector<string>::iterator nums = a.begin()+1 ; nums!=a.end() ; nums++ ){
      if(comp2(*best,*nums)){
        best = nums;
        // cout<<" - changing best to "<<*best<<"\n";
      }
    }

    ret<<*best;
    a.erase(best);
  }

  string result;
  ret >> result;
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
