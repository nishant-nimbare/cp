#include <iostream>
#include <vector>

using namespace std;

vector<int> visited;

size_t count = 0;

void dfs(vector<vector<int> > &adj, int cur, int c){

    // std::cout<<" - - dfs in "<<cur<<'\n';
    visited[cur] = c;

    for(int neigh : adj[cur]){
        if(visited[neigh] == -1){
          dfs(adj, neigh, c);        
        }
    }
    
}


int getUnvisited(){
  // std::cout<<" - finding uv \t";
  for(int v=0; v<visited.size(); v++){
    // std::cout<<v<<" ";
    if( visited[v]  == -1 ) return v;
  }

  return -1;
}

int number_of_components(vector<vector<int> > &adj) {
  int res = 0;
  visited.resize(adj.size(), -1);

  int uv = getUnvisited();
  // std::cout<<"\n uv:"<<uv<<'\n';

  while(uv != -1){
    count+=1;
    dfs(adj, uv, count);
    uv = getUnvisited();
  }

  //write your code here
  return count;
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
  std::cout << number_of_components(adj);
}
