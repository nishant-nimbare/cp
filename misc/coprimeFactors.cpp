#include <bits/stdc++.h>
using namespace std;


unordered_map<int, int> getFactors(int n){
    unordered_map<int, int> res;

    int t = n;

    while(t%2 == 0){
        res[2]+=1;
        t/=2;
    }

    for(int i=3; i*i<=n; i+=2){

        while( t%i == 0){

            res[i]+=1;
            t/=i;
            cout<<"res "<<i<<" "<<res[i]<<"\n -"<<t<<"\n";
        
        }
    }

    if(t>1) res[t] +=1;

    return res;
}


int main(int argc, char const *argv[]){
    
    int n = 12;

    if(argc>1){
        
        cout<<argv[1]<<endl;

        n =stoi(argv[1]);
    }

    unordered_map<int, int> facts =  getFactors(n);

    unordered_map<int, int>::iterator itr;

    int ans =1;
    
    cout<<" facts \n";
    for(itr = facts.begin(); itr!= facts.end(); itr++){
        cout<<itr->first<<" -> "<<itr->second<<"\n";    

        ans *= (itr->second + 1);
    }

    cout<<" ans "<<ans<<"\n";


}