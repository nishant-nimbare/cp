#include <bits/stdc++.h>
using namespace std;

// done

struct item {
  double vpw;
  int w;
  int v;
};

bool comp( const item& lhs, const item& rhs){
  return (lhs.vpw > rhs.vpw);
}


double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  vector<item> items;

  for(int i=0; i<values.size(); i++){
    items.push_back(item());
    items[i].w = weights[i];
    items[i].v = values[i];
    items[i].vpw = ((double)values[i]/(double)weights[i]);
  }

  sort( items.begin(), items.end(), &comp );

  //start greedy 

  for(item itm: items){
    
    // cout<<" - "<<itm.vpw<<" "<<itm.v<<" "<<itm.w<<"\n";

    int temp = min(capacity,itm.w);

    capacity = capacity - temp;
    value += (double)(temp*itm.vpw);
    if(capacity <= 0 ) break;

  }


  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
