#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;
using std::make_pair;

class HeapBuilder {
 private:
  vector<int> data_;
  vector< pair<int, int> > swaps_;

  void WriteResponse() const {
    cout << swaps_.size() << "\n";
    for (int i = 0; i < swaps_.size(); ++i) {
      cout << swaps_[i].first << " " << swaps_[i].second << "\n";
    }
  }

  void ReadData() {
    int n;
    cin >> n;
    data_.resize(n);
    for(int i = 0; i < n; ++i)
      cin >> data_[i];
  }

  void GenerateSwaps() {
    swaps_.clear();
    // The following naive implementation just sorts 
    // the given sequence using selection sort algorithm
    // and saves the resulting sequence of swaps.
    // This turns the given array into a heap, 
    // but in the worst case gives a quadratic number of swaps.
    //
    // TODO: replace by a more efficient implementation

  
    int height = log2(data_.size());

    // cout<<" inside generate \n";
    // cout<<height<<" : height \n";

    for(int lvl = height; lvl>=0; lvl-- ){
  
      // cout<< lvl <<" : lvl \n";

      for(int i = (1<<(lvl-1))-1; i< (1<<lvl)-1; i++){
        // cout<<i<<" i\t ";
        shiftDown(i);
      }
      // cout<<'\n';
    }

    // cout<<"------------------------------------------\n";
    

    // for (int i = 0; i < data_.size(); ++i)
    //   for (int j = i + 1; j < data_.size(); ++j) {
    //     if (data_[i] > data_[j]) {
    //       swap(data_[i], data_[j]);
    //       swaps_.push_back(make_pair(i, j));
    //     }
    //   }
  }

  int parent(int i){
    return (i-1)/2;
  }

  int lc(int i){
    int l =  (2*i)+1;
    return (l < data_.size())?(l):(-1);
  }


  int rc(int i){
    int r =  (2*i)+2;
    return (r < data_.size())?(r):(-1);
  }

  int log2(int i){
    return std::log( i ) / std::log( 2 );
  }

  void shiftDown(int i){
    int l = lc(i);
    int r = rc(i);
    // int minc = (data_[l] < data_[l+1]) ? (l) : (l+1); 
    int minc =-1;
    if(l!=-1) minc=l;
    if( (r!=-1) && ( data_[r] < data_[l] ) ) minc=r;


    // cout<<"\n |- inside shiftdown \n";
    // cout<<" parent : "<<data_[i]<<" lc : "<<data_[l]<<" rc : "<<data_[r]<<" \n";

    while( (minc!=-1) && (data_[i] > data_[minc]) ){

      // cout<<" - shifting down "<<data_[i]<<" -> "<<i<<" \n";
      
      swap( data_[i], data_[minc] );
      swaps_.push_back(make_pair(i, minc));
    
      i=minc;
      l = lc(i);
      r = rc(i);    

      minc=-1;
      if(l!=-1) minc=l;
      if( (r!=-1) && ( data_[r] < data_[l] ) ) minc=r;
    
    }  
  }

 public:
  void Solve() {
    ReadData();
    GenerateSwaps();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  HeapBuilder heap_builder;
  heap_builder.Solve();
  return 0;
}
