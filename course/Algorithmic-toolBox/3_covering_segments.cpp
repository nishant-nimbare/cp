#include <bits/stdc++.h>
using namespace std;

// done

struct Segment {
  int start, end;
};

bool comp(const Segment& lhs, const Segment& rhs){
  return (lhs.end < rhs.end);
}

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  //write your code here
  // for (size_t i = 0; i < segments.size(); ++i) {
  //   points.push_back(segments[i].start);
  //   points.push_back(segments[i].end);
  // }

  sort(segments.begin(), segments.end(), &comp);

  while(segments.size()>0){
    
    vector<Segment>::iterator itr = segments.begin();
    int cur = itr->end;
    points.push_back(cur);

    segments.erase(itr);

    //remove overlapping 
    while(itr != segments.end()){
      if( ( itr->start<=cur ) &&  (cur<=itr->end) ){
        //overlapping
        segments.erase(itr);
      }else{
        itr++;
      }
    }

  }

  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
