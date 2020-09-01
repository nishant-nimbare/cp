#include<bits/stdc++.h>
using namespace std;

int max1Dsum(vector<int>& oneD, int k){
        
        int l=0,r=0, sum=0, max_sum=INT_MIN;
        
        //calculate prefix sum
        for(int i=1;i<oneD.size();i++){
            oneD[i] = oneD[i] + oneD[i-1];
        }
        
        deque<int> dq;
        
        for(int i=0; i<oneD.size(); i++){
            
            if( oneD[i] <= k ) max_sum = std::max(max_sum, oneD[i]);
            
            while( !dq.empty() && dq.front() >= oneD[i] - k ){
                max_sum = std::max(max_sum, oneD[i]-dq.front());
                dq.pop_front();
            }
            
            while( !dq.empty() && dq.back()<=oneD[i] ){
                dq.pop_back();
            }
            
            dq.push_back(oneD[i]);
        }
        
        return max_sum;
}


void printSet(set<int>& mset){
    for(int i:mset)
        cout<<i<<" ";

    cout<<"\n";
}

int maxWithSet(vector<int>& oneD, int k){
    set<int> cumset;
    cumset.insert(0);
    int best=INT_MIN,cum=0;
    for(int i=0; i<oneD.size(); i++){
        cum+=oneD[i];
        set<int>::iterator sit=cumset.upper_bound(cum-k-1);
        if(sit!=cumset.end()){
            best=max(best,cum-*sit);
            cout<<" - "<<cum-*sit<<"\n";
        }
        cumset.insert(cum);
        printSet(cumset);
    }
    return best;
}


int main(){

    vector<int> oneD ={1,1};
    cout<<maxWithSet(oneD,2)<<"\n";
}