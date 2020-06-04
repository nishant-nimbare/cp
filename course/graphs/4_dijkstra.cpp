#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;
using std::cout;


priority_queue<pair<int,int>> q;
vector<int> dist;
vector<bool> seen;

int distance(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, int t) {
  //write your code her
  dist.resize(adj.size(), INT32_MAX);
  seen.resize(adj.size(), false);

  dist[s] = 0;
  q.push({0,s});

  // cout<<" cost matrix\n";
  // for(int i=0; i<cost.size(); i++){
  //   for(int k: cost[i]) cout<<k<<" ";
  //   cout<<"\n";
  // }

  while(!q.empty()){

    int cur = q.top().second;

    // cout<<" cur "<<q.top().second<<" : "<<q.top().first<<'\n';

    q.pop();


    if(seen[cur]) continue;
    else seen[cur] = true;

    if(cur == t) return (dist[cur] == INT32_MAX )?(-1):(dist[cur]);

    //relax each edge of cur
    for(int n=0; n < adj[cur].size(); n++ ){

      int neigh = adj[cur][n];
      
      if(dist[neigh] > dist[cur]+cost[cur][n] ){
        
        dist[neigh] = dist[cur]+cost[cur][n];
        q.push({-(dist[neigh]), neigh });
        // cout<<" - changing dist of "<<neigh<<" : "<<dist[neigh]<<"\n";

      }      
  
    }

  }

  return (dist[t] == INT32_MAX )?(-1):(dist[t]);
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, cost, s, t);
}
