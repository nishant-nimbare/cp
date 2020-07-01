#include <bits/stdc++.h>
using namespace std;

struct env{
    int i, w, h;
    env(int x, int y, int z) : i(x), w(y), h(z){} 
};


bool comp(const env &lhs, const env &rhs){

    if( lhs.h == rhs.h ) return lhs.w < rhs.w;

    return lhs.h < rhs.h;
}


bool fit(env e1, env e2){
    return (e1.h < e2.h && e1.w < e2.w);
}

vector<env> envs;

//max possible envs till here , idx of prev env
vector<pair<int,int>> dp;

int main(int argc, char const *argv[]){

    int n, cw, ch, wi, hi;
	cin>>n>>cw>>ch;

    env card = env(0, cw, ch);

	for (int i = 1; i <= n; i++){
        cin>>wi>>hi;
        envs.push_back(env(i, wi, hi));
    }

    sort(envs.begin(), envs.end(), &comp);

    for(auto e:envs) {
        // cout<<e.i<<" ";
      
        if(fit(card, e)) dp.push_back( make_pair( 1, -1 ) );
        else dp.push_back( make_pair( 0, -1 ) );
    
    }

    // cout<<"\n ---------- \n";
    
    int globalMax=0, globalIdx = -1;

    // envs has 0 indexing
    for (int i = 1; i < n ; i++){
        
        if( !fit(card, envs[i]) ) continue;

        int curMax = -1, curIdx=-1;

        for (int j = 0; j < i; j++){
            
            if( ( dp[j].first>0 ) && fit(envs[j], envs[i]) ) {

                if(curMax < dp[j].first){
                    curMax = dp[j].first;
                    curIdx = j;
                }    
            }
        }

        if(curIdx != -1){
            dp[i].first += curMax;
            dp[i].second = curIdx; 
        }

        if(globalMax < dp[i].first ){
            globalMax = dp[i].first;
            globalIdx = i;
        }

    }
    

    cout<<globalMax<<"\n";
    
    stack<int> sc;

    while (globalIdx>=0){
        sc.push(envs[globalIdx].i);
        globalIdx = dp[globalIdx].second;   
    }

    while(!sc.empty()){
        cout<<sc.top()<<" ";
        sc.pop();
    }

	return 0;
}