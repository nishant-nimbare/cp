#include <bits/stdc++.h>

#define DEBUG true

#ifdef DEBUG
#define dout cout
#else
#define dout 0 && cout
#endif

#define PS <<" - "<<
#define PG <<"  "<<
#define PE <<endl

using namespace std;

void printVec(vector<int> a){ for(auto x:a) cout<<x<<" "; cout<<endl;}

// printBT for printing tree horizontally


int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n,l;
  cin>>n>>l;

  vector<int> arr(n);
  for(int &x:arr) cin>>x;

  sort(arr.begin(), arr.end());

  //for(int x:arr) cout<<x;
  int ans = max( 2*(arr[0]-0), 2*(l-arr[n-1]) );

  for (int i = 0; i < n-1; i++) {
    ans = max(ans, arr[i+1] - arr[i]);
  }

  float d = (float)ans/(float)2;

  cout<< std::fixed << std::setprecision(10)<<d<<endl;



  return 0;
}
