#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;

struct edge
{
  double size;
  int from, to;
  edge(double s, int f, int t): size(s), from(f), to(t) {}
};


vector<edge> edges;

// disjoint set
vector<int> parent;
size_t noSets;

int findParent(int n){
  if(parent[n] == n) return n;

  // path reduction
  parent[n]= findParent( parent[n] );

  return parent[n];
}

void combine(int a, int b){
  a = findParent(a);
  b = findParent(b);

  if(a != b) parent[b] = a;
}


// comparator for sorting edges
bool comp(const edge &lhs, const edge &rhs){
    return lhs.size <= rhs.size;
}

double minimum_distance(vector<int> x, vector<int> y) {
  double result = 0.;

  // calculate all edges and sort
  for(int i=0; i<x.size()-1; i++){
    for(int j=i+1; j<x.size(); j++){
      
      double length = ( (x[i] - x[j]) * (x[i] - x[j]) ) + ( ( y[i] - y[j] ) * ( y[i] - y[j] ) ) ;
      length = sqrt(length);  
      
      edges.push_back(edge( length, i, j ));
    }
  }

  sort( edges.begin(), edges.end(), &comp);


  // make V different sets
  for(int i=0; i<x.size(); i++ ){
    parent.push_back(i); 
  }
  noSets = x.size();
  // kruskals

  // for(int e=0; e<edges.size(); e++){
  for(edge e : edges){

    // cout<<" parent list \n";
    // for( int p : parent ) cout<<p<<" ";
    // cout<<"\n";
    
    if(findParent(e.from) != findParent(e.to)){
        // cout<<" adding edge "<< x[e.from] <<", "<< y[e.from] <<"  ->  "<<x[e.to]<<", "<<y[e.to]<<"   :  "<<e.size<<"\n";
        result += e.size;
        combine(e.from, e.to);
        noSets -=1;
        if(noSets == 1){
          // only one connected 
          break;
        }
    }
  
  }

  return result;
} 

int main() {
  size_t n;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cout << std::setprecision(10) << minimum_distance(x, y) << std::endl;
}
