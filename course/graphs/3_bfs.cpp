#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

queue<int> q;
vector<bool> visited; 
vector<int> dist;


int distance(vector<vector<int> > &adj, int s, int t) {
  //write your code here
  visited.resize(adj.size(), false);
  dist.resize(adj.size(), -1);
  dist[s] =0;  

  q.push(s);

  while(!q.empty()){

    int cur = q.front();
    q.pop();

    for(int neig : adj[cur]){
      if( !visited[neig] ){
        visited[neig]=true;
        dist[neig] = dist[cur]+1;
        q.push(neig);

        if(neig == t){ // destination found
          return dist[t];
        }
      }
    }
  }

  return dist[t];
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
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, s, t);
}
