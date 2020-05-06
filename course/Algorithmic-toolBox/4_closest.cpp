#include <bits/stdc++.h>

using std::vector;
using std::string;
using std::pair;
using std::min;
using namespace std;

struct point{
  int x;
  int y;
  point(int x1, int y1){
    x=x1;
    y=y1;
  }
};


bool compx(const point& lhs, const point& rhs){
  return (lhs.x<rhs.x);  //sort on x
}

bool compy(const point& lhs, const point& rhs){
  return (lhs.y<rhs.y);  //sort on x
}

double minimal_distance(vector<point>& points, int l, int r) {
  //write your code here
  double min=0.0;
  //base case

  if( (l==r) || (l+1==r)) // 0 or 1  points
    return INT_MAX;   

  else if(l+2==r){
    
    return sqrt(
    ((points[l].x - points[l+1].x)*(points[l].x - points[l+1].x)) +
    ((points[l].y - points[l+1].y)*(points[l].y - points[l+1].y))
    );
  }
  
  
  // more than 2 elements 


  int m = (r-l)/2 + l;

  double lhs = minimal_distance(points,l,m);
  double rhs = minimal_distance(points,m,r);

  min = (lhs<rhs)?(lhs):(rhs);
  
  vector<point> filtered;
  for(int i=l; i<r; i++){
    if( ( points[m].x - points[i].x ) <= min ) filtered.push_back(points[i]);
  }

  sort( filtered.begin(), filtered.end(), &compy); // sort by y


  // wrt every point in filtered check only next 7 points
  double temp;
  for( int i=0; i<filtered.size(); i++){
    for( int j=i+1; ((j-i)<=7 && j<filtered.size()) ; j++ ){
      temp =  sqrt(
        ((filtered[i].x - filtered[j].x)*(filtered[i].x - filtered[j].x)) +
        ((filtered[i].y - filtered[j].y)*(filtered[i].y - filtered[j].y))
      );

      if(temp<min) min = temp;

    }
  }


  return min;
}

int main() {
  size_t n;
  std::cin >> n;
  // vector<int> x(n);
  // vector<int> y(n);
  vector<point> points;
  int X,Y;
  for (size_t i = 0; i < n; i++) {

    std::cin >> X >> Y;
    points.push_back(point(X,Y));

  }

  sort(points.begin(), points.end(), &compx);
  
  std::cout << std::fixed;
  std::cout << std::setprecision(9) << minimal_distance(points, 0, points.size()) << "\n";
}
