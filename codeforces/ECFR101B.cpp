#include <bits/stdc++.h>

#define DEBUG true

#ifdef DEBUG
#define dout cout
#else
#define dout 0 && cout
#endif

#define PS <<" - "<<
#define PG <<"  "<<
#define PE <<endl

using namespace std;

void printVec(vector<int> a){ for(auto x:a) cout<<x<<" "; cout<<endl;}

int greedy(vector<int> &red, vector<int> &blue){

  int a=0, b=0, n= red.size(), m = blue.size();

  int global_best = 0, cur =0;

  while(a<n && b<m){

    if( red[a] > blue[b] ){
      cur += red[a];
      a++;
    }

    else{
      cur += blue[b];
      b++;
    }

    global_best = max(global_best, cur);
  }

  while( a<n ){
    cur += red[a];
    a++;
    global_best = max(global_best, cur);
  }

  while( b<m ){
    cur += blue[b];
    b++;
    global_best = max(global_best, cur);
  }

  return global_best;
}

int dp[100][100] = {-1};
// create sequence in reverse
int go(vector<int> &red, vector<int> &blue, int a, int b){

  if(a<0 || b<0) return 0;

  if(dp[a][b] == -1){

    //if(a==0 && b<=0) return max(red[a],0);

    int best = 0, sum = 0;
    if( a==0 ){

      for(int x=0; x<=b; x++){
        sum += blue[x];
        best = max(best, sum);

      }

      sum += red[a];
      best = max(best, sum);

      dp[a][b] = best;
      
      dout PS a PG b PG dp[a][b] PE;
      return best;
    }


    if( b==0 ){

      for(int x=0; x<=a; x++){
        sum += red[x];
        best = max(best, sum);

      }

      sum += blue[b];
      best = max(best, sum);

      dp[a][b] = best;
      dout PS a PG b PG dp[a][b] PE;
      return best;
    }
    //if(a<=0 && b==0) return max(blue[b], 0);

    // 2 choice, choose red before or choose blue
    int c1 = 0, c2 =0;

    if(a>0)  c1 = go(red,blue,a-1,b);

    if(b>0)  c2 = go(red,blue,a,b-1);

    int res = max(
        max(c1, c1+red[a]),
        max( c2, c2+ blue[b])
        );

    dp[a][b] = max(res, 0);
    dout PS a PG b PG c1 PG c2 PG dp[a][b] PE;
  }

  return dp[a][b];
}


int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--) {
    int n, m;
    cin >> n;

    vector<int> red(n);

    for (int i = 0; i < n; i++) {
      cin>>red[i];
    }

    cin >> m;
    vector<int> blue(m);

    for (int i = 0; i < m; i++) {
      cin>>blue[i];
    }
    memset(dp, -1, sizeof(dp));

    red.push_back(0);
    blue.push_back(0);
    cout<<go(red, blue, n, m)<<endl;    
  }

  return 0;
}
