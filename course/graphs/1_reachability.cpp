#include <iostream>
#include <vector>

using std::vector;
using std::pair;

vector<bool> visited;


bool dfs(vector<vector<int> > &adj, int cur, int dest){

    visited[cur] = true;

    if(cur == dest) return true;

    for(int neigh : adj[cur]){
        if(!visited[neigh]){
          
          if(dfs(adj, neigh, dest)){
            return true;
          }
        
        }
    }
    return false;
}

int reach(vector<vector<int> > &adj, int x, int y) {
  //write your code here
  visited.resize(adj.size(), false);


  return ( dfs(adj,x,y) ) ? (1):(0);
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int x, y;
  std::cin >> x >> y;
  std::cout << reach(adj, x - 1, y - 1);
}
