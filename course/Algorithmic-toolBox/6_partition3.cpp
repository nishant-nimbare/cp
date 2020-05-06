#include <iostream>
#include <vector>

using std::fill;
using std::max;
using std::vector;
using std::cout;
    //    sum
short int table[(1 << 20)];

int partition3(vector<int> &A) {
  //write your code here

  size_t n = A.size();
  int twoPowN = (1<<n);

  // cout<<" TWO POW N "<<twoPowN<<" \n";
  unsigned short int sum=0;
  int mmax=-1;
  for(int i:A) {
    sum+=i;
    mmax=max(mmax,i);
  }

  if(sum%3 != 0) return 0;

  int target = sum/3;
  if(mmax>target) return 0; // some element is bigger than a single partition

  fill(table, table+(1<<n), -1);
  table[0] = 0;


  //try all posible subsets of a
  for(int mask = 0; mask< twoPowN; mask++){

    // std::cout<< mask <<"  "<<table[mask]<<"\n";
    if(table[mask]==-1) continue;

    //try to insert all elements
    for(size_t k=0; k<n; k++){
      //check if kth elem is already used
      
      // cout<<" - trying "<<A[k]<<" for "<<mask<<" \n";
      if(mask & (1<<k)) continue;

      // check if adding kth elem doesn't cross the target
      if( table[mask] + A[k] <= target){
        // cout<<" - - adding "<<A[k]<<" to "<<mask<<" = "<<(table[mask] + A[k]) % target<<"\n";
        table[mask | (1<<k)] = ( table[mask] + A[k] ) % target;

      }
    }
  }



  return (table[twoPowN-1]==0)?(1):(0);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i) {
    std::cin >> A[i];
  }
  std::cout << partition3(A) << '\n';
}
