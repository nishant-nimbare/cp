#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_set>

using std::vector;
using std::pair;
using std::cout;


int count=0;
std::unordered_set<int> unvisited; 
vector<pair<int, int>> postfixOrder;

vector<int> label;


void dfs(vector<vector<int> > &adj, int x) {

  unvisited.erase(x);

  for(int neig : adj[x]){
    if( unvisited.find(neig) != unvisited.end() ){
      dfs(adj, neig);
    }
  }

  count+=1;
  postfixOrder.push_back({count, x});
}   

void dfs2(vector<vector<int> > &adj, int x, int l) {

  unvisited.erase(x);

  for(int neig : adj[x]){
    if( unvisited.find(neig) != unvisited.end() ){
      dfs2(adj, neig, l);
    }
  }

  label[x] = l;

}   

void getPostFixOrder(vector<vector<int> > &graph){

  // postfixOrder.resize(graph.size(), -1);
 
  for(int i=graph.size()-1; i>=0; i--){
    unvisited.insert(i);
  }

  while(!unvisited.empty()){

    // cout<<"starting dfs with "<<*unvisited.begin()<<"\n";
    dfs(graph, *unvisited.begin() ); 
  }


  // cout<<"pfOrder\n";
  // for(auto pair: postfixOrder) cout<<pair.first<<"->"<<pair.second<<"\n";
  // cout<<"\n";

}

int number_of_strongly_connected_components(vector<vector<int> > &adj) {
  int result = 0;

  // create reverse graph
  vector<vector<int> > rev(adj.size(), vector<int>());

  for(int i=0; i<adj.size(); i++){
    for(int j : adj[i]){
        rev[j].push_back(i);
    }
  }

  // cout<<"reverse graph\n";
  // for(int i=0; i<rev.size(); i++){
  //   cout<<i<<" -> ";
  //   for(int j : rev[i]) cout<<j<<", ";
  //   cout<<"\n";
  // }

  getPostFixOrder(rev);

  unvisited.clear();

  for(int i=adj.size()-1; i>=0; i--){
    unvisited.insert(i);
  }

  label.resize(adj.size(), -1);

  while(!postfixOrder.empty()){
    int t = postfixOrder.back().second;
    postfixOrder.pop_back();

    if(unvisited.find(t) != unvisited.end() ){
        result+=1;
        dfs2(adj, t, result);
    }
  }

  // cout<<" \n\n\n\n";
  return result;
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
  std::cout << number_of_strongly_connected_components(adj);
}
