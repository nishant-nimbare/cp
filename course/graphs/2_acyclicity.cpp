#include <iostream>
#include <vector>

using std::vector;
using std::pair;

vector<bool> visit;
vector<bool> visited;

int getUnvisited(){
  // std::cout<<" - finding uv \t";
  for(int v=0; v<visit.size(); v++){
    // std::cout<<v<<" ";
    if( !visit[v] ) return v;
  }
  return -1;
}

bool dfs(vector<vector<int> > &adj, int cur){

  visit[cur] = true;

  if( visited[cur] ){
    // cycle detected
    return true;
  } 

  visited[cur] = true;
  for(int neig: adj[cur]){
    
    if(dfs(adj,neig)){
      return true;
    }
  }

  visited[cur] = false;
  return false;
}


int acyclic(vector<vector<int> > &adj) {
  //write your code here
  visited.resize( adj.size(), false);
  
  visit.resize(adj.size(), false);

  int uv = getUnvisited();
  // std::cout<<"\n uv:"<<uv<<'\n';

  while(uv != -1){
  
    if( dfs(adj, uv) ) return 1;
  
    uv = getUnvisited();
  }

  return 0;
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
  std::cout << acyclic(adj);
}
