#include <iostream>
#include <vector>

using std::vector;
using std::cout;

vector<long int> dist;


int negative_cycle(vector<vector<int> > &adj, vector<vector<int> > &cost) {
  //write your code here
  dist.resize(adj.size(), INT32_MAX);
  dist[0] = 0;

  // cout<<" cost matrix\n";
  // for(int i=0; i<cost.size(); i++){
  //   for(int k: cost[i]) cout<<k<<" ";
  //   cout<<"\n";
  // }


  int V = adj.size();
  bool change;

  for(int v =0; v<V; v++){
    change = false;
    // cout<< v <<" v \n";
    for(int cur=0; cur<adj.size(); cur++){

      // if(dist[cur]==INT32_MAX) continue;

      for(int n=0; n < adj[cur].size(); n++ ){
        int neigh = adj[cur][n];

        if(dist[neigh] > dist[cur]+cost[cur][n] ){        
            dist[neigh] = dist[cur]+cost[cur][n];
            change = true;
            // cout<<" - changing dist of "<<neigh<<" : "<<dist[neigh]<<"\n";
        }    
      
      }
    }
  }

  return (change)?(1):(0);
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
  std::cout << negative_cycle(adj, cost);
}
