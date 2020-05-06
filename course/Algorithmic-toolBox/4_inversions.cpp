#include <iostream>
#include <vector>
#define lli long long int
using std::vector;
using std::cout;

void printArr(vector<int> &a){
  for(auto i:a) cout<<i<<" ";
  cout<<'\n';
}

lli merge(vector<int>& a, int l, int r, int m) {
    lli inver = 0;
    vector<int> temp;
    // 1st array l:m-1 and m:r-1

    int i = l, j = m;
    while (i < m && j < r) {
        if (a[i] > a[j]) {
            
            inver += m-i;

            temp.push_back(a[j]);
            j++;
        } else {
            temp.push_back(a[i]);
            i++;
        }
    }

    // if i < m it means that elements remaining b\w i - m are all bigger than all the elements in m - r
    // if((i < m) && (j>=r)) inver+=(r-m)*(m-i-1);


    while (i < m) {
        temp.push_back(a[i]);
        i++;
    }

    while (j < r) {
        temp.push_back(a[j]);
        j++;
        // inver++;
    }

    for(int k = l; k<r; k++){
      a[k]=temp[k-l];
    }

    return inver;

}

lli mergeSort(vector<int>& a, int l, int h) {
    if (l >= h) return 0;  // zero elements

    if (l + 1 == h) return 0;  // 1 element 0 inversion

    int m = l + ((h - l) / 2);

    lli li = mergeSort(a, l, m);
    lli ri = mergeSort(a, m, h);

    lli i = merge(a, l, h, m);

    // cout<<" -- sorted " <<l<<" "<<h<<" inv -> "<< ( i) <<"\n";
    // printArr(a);
    // cout<<'\n';

    return (li + ri + i);
}

lli start(vector<int>& a, vector<int>& b){
  
  vector<int> AB;
  AB.reserve( a.size() + b.size() ); // preallocate memory
  AB.insert( AB.end(), a.begin(), a.end() );
  AB.insert( AB.end(), b.begin(), b.end() );

  return mergeSort(AB, 0, AB.size());
}

long long get_number_of_inversions(vector<int>& a, vector<int>& b, size_t left,
                                   size_t right) {
    long long number_of_inversions = 0;
    if (right <= left + 1) return number_of_inversions;
    size_t ave = left + (right - left) / 2;
    number_of_inversions += get_number_of_inversions(a, b, left, ave);
    number_of_inversions += get_number_of_inversions(a, b, ave, right);
    // write your code here
    return number_of_inversions;
}

int main() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); i++) {
        std::cin >> a[i];
    }
    vector<int> b(a.size());
    std::cout << mergeSort(a, 0, a.size()) << '\n';
}
