#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>


using std::cout;
using std::vector;
using std::pair;

// vector<bool> visit;

std::unordered_set<int> unvisited; 

/*
int getUnvisited(){
  // std::cout<<" - finding uv \t";
  for(int v=0; v<visit.size(); v++){
    // std::cout<<v<<" ";
    if( !visit[v] ) return v;
  }
  return -1;
}
*/

void dfs(vector<vector<int> > &adj, vector<int> &order, int x) {
  //write your code here
  // visit[x]=true;

  unvisited.erase(x);

  for(int neig : adj[x]){
    if( unvisited.find(neig) != unvisited.end() ){
      dfs(adj, order, neig);
    }
  }

  order.push_back(x);
}     

vector<int> toposort(vector<vector<int> > adj) {
  vector<int> used(adj.size(), 0);
  vector<int> order;
  //write your code here

  for(int i=0; i<adj.size(); i++){
    unvisited.insert(i);
  }

  // visit.resize(adj.size(), false);

  // int uv = getUnvisited();
  // std::cout<<"\n uv:"<<uv<<'\n';

  while(!unvisited.empty()){
    dfs(adj, order, *unvisited.begin() ); 
  }


  std::reverse(order.begin(), order.end());

  return order;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  vector<int> order = toposort(adj);
  for (size_t i = 0; i < order.size(); i++) {
    std::cout << order[i] + 1 << " ";
  }
}
