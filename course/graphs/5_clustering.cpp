#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <vector>
#include <cmath>

using namespace std;


// Disjoint Sets
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



struct edge
{
  double size;
  int from, to;
  edge(double s, int f, int t): size(s), from(f), to(t) {}
};

vector<edge> edges;

// comparator for sorting edges
bool comp(const edge &lhs, const edge &rhs){
    return lhs.size <= rhs.size;
}


double clustering(vector<int> x, vector<int> y, int k) {
  //write your code here

   // calculate all edges and sort
  for(int i=0; i<x.size()-1; i++){
    for(int j=i+1; j<x.size(); j++){
      
      // double length = ( (x[i] - x[j]) * (x[i] - x[j]) ) + ( ( y[i] - y[j] ) * ( y[i] - y[j] ) ) ;

      double _x = (double) x[i] - x[j], _y = (double) y[i] - y[j];

      double length = pow(_x, 2.0) + pow(_y, 2.0);
      length = sqrt(length);  
      
      edges.push_back(edge( length, i, j ));
    }
  }

  sort( edges.begin(), edges.end(), &comp);

  if(k == x.size() ) return edges[0].size;

  // make V different sets
  for(int i=0; i<x.size(); i++ ){
    parent.push_back(i); 
  }
  noSets = x.size();
  
  int next = -1;

  // kruskals
  for(int i=0; i< edges.size(); i++){
    
    edge e = edges[i];
    
    // cout<<" parent list \n";
    // for( int p : parent ) cout<<p<<" ";
    // cout<<"\n";
    
    if(findParent(e.from) != findParent(e.to)){
        // cout<<" adding edge "<< x[e.from] <<", "<< y[e.from] <<"  ->  "<<x[e.to]<<", "<<y[e.to]<<"   :  "<<e.size<<"\n";
       
        combine(e.from, e.to);
        noSets -=1;
        if(noSets == k){
          // k clusters are formed 
          next = i+1;
          break;
        }
    }

  }
  

  return (next<edges.size() && next != -1) ? (edges[next].size ) : (-1.);
} 

int main() {
  size_t n;
  int k;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cin >> k;
  std::cout << std::setprecision(13) << clustering(x, y, k) << std::endl;
}
