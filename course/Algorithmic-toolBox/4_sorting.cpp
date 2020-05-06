#include <iostream>
#include <vector>
#include <cstdlib>

/*
x
2 5 | 9 4 8 3 6 1
         

*/

using std::vector;
using std::swap;
using std::pair;
using std::cout;

void printArr(vector<int> &a){
  for(auto i:a) cout<<i<<" ";
  cout<<'\n';
}

pair<int,int> partition3(vector<int> &a, int l, int r){
  int pivot = a[r];
  int s=l,e=r,cur=l;

  while(cur<=e){

      if(a[cur]<pivot){
        //put this element back
        swap(a[cur],a[s]);
        s++;
        cur++;

      }
      else if(a[cur]>pivot){

        swap(a[cur],a[e]);
        e--;

      }
      else{
        cur++;
      }
  }

  return std::make_pair(s-1,cur);
}

int partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[r], a[k]);
  // int m = partition2(a, l, r);
  // cout<<" - part "<<l<<' '<<r<<' '<<a[r]<<"\n arr is \n";

  pair<int,int> m = partition3(a,l,r);
  
  // printArr(a);
  // cout<<"\n";

  randomized_quick_sort(a, l, m.first);
  randomized_quick_sort(a, m.second, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
