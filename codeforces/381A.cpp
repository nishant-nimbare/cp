#include <bits/stdc++.h>
using namespace std;

int main(){
    size_t n;
    cin>>n;
    int num[n];

    for(size_t i=0; i<n; i++) cin>>num[i];

    int f=0,b=n-1;

    int  Sereja=0 , Dima=0;
    bool play=true;

    while(f<=b){

        int mcur=0;

        if(num[f]>num[b]){
            mcur = num[f];    
            f++;
        }else{
            mcur = num[b];    
            b--;
        }

        // cout<<" -  "<<f<<"  "<<b<<"  "<<mcur<<"\n"; 

        if(play){
            Sereja+= mcur;    
        }else{
            Dima += mcur;
        }

        play = !play;
    }     

    cout<<Sereja<<' '<<Dima;
}