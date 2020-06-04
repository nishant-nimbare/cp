#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;


queue<int> q;
vector<bool> visited; 
vector<int> dist;


int bipartite(vector<vector<int> > &adj) {
  //write your code here
  
  visited.resize(adj.size(), false);
  q.push(0);

  dist.resize(adj.size(), -1);
  dist[0] =0;  


  while(!q.empty()){

    int cur = q.front();
    q.pop();

    for(int neig : adj[cur]){

      if(visited[neig]) {
        
        if ((dist[neig] - dist[cur]) % 2 == 0) return 0;
      
      }

      if( !visited[neig] ){

        visited[neig]=true;
        dist[neig] = dist[cur]+1;
        q.push(neig);

      }

    }
  }


  
  return 1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << bipartite(adj);
}
