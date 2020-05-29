#include <bits/stdc++.h>
using namespace std;

// unsigned long long int mhash[2000000];


int main(int argc, char const *argv[]){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long int n ;
    cin >>n;

    // mhash[0] = 1;
    // for(size_t i=1; i<2000000; i++){

    //     mhash[i] = (mhash[i-1]*5)%100;
    //     if(mhash[i]<0) mhash[i]+=100;

    //     cout<<i<<"  "<<mhash[i]<<'\n';
    // }


    if(n==0) cout<<1<<'\n';
    else if(n==1) cout<<5<<'\n';
    else cout<<25<<'\n';
    // else cout<<0;   
    
}