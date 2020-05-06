// #include <iostream>
// #include <vector>
#include <bits/stdc++.h>
using namespace std;

struct item{
  int point; 
  int index;
  char type; // s, e, p 
  item(int p, char t, int i){
    point=p;
    type=t;
    index=i;
  }
};

void printArr(vector<item> &a){
  for(auto i:a) cout<<i.point<<","<<i.type<<"  ";
  cout<<'\n';
}

bool comp(const item& lhs, const item& rhs ){
  
  if(lhs.point == rhs.point){
      // overlaping points prefer start , point , end

      if((lhs.type == 's') || (lhs.type == 'p' && rhs.type=='e') ) return true;
      else return false;
  }
  
  return lhs.point < rhs.point;

}

vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  //write your code here
  vector<item> all;

  for(int s=0; s < starts.size(); s++ ) all.push_back(item( starts[s], 's', s)); 
  for(int e=0; e < ends.size(); e++ ) all.push_back(item( ends[e], 'e', e)); 
  for(int p=0; p < points.size(); p++ ) all.push_back(item( points[p], 'p', p)); 

  sort(all.begin(), all.end(), &comp); 

  // printArr(all);

  int active=0;
  for(item i: all){
    if(i.type=='s') active++;
    else if(i.type=='e') active--;
    else
    {
      cnt[i.index]=active;
    }
    
  }

  return cnt;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++) {
    for (size_t j = 0; j < starts.size(); j++) {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }
  return cnt;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<int> starts(n), ends(n);
  for (size_t i = 0; i < starts.size(); i++) {
    std::cin >> starts[i] >> ends[i];
  }
  vector<int> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    std::cin >> points[i];
  }
  //use fast_count_segments
  vector<int> cnt = fast_count_segments(starts, ends, points);
  for (size_t i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i] << ' ';
  }
}
