#include <bits/stdc++.h>
using namespace std;


vector<int> withoutD;
vector<int> withD;

int prime = 1000000000 + 7;

int main(int argc, char const *argv[]){

    int n,k,d;
    cin>>n>>k>>d;

    withoutD.resize( n+1, 0);
    withD.resize( n+1,  0);

    withoutD[0] = 1;


    for(int i=1; i<=n; i++){

        for(int j=1; j<=min(k, i) ; j++){
            
            if(j<d){
                // cout<<"- from "<<i-j<<" : "<<withoutD[i-j]<<"\n";
                withoutD[i] = ( withoutD[i] + withoutD[i-j] )%prime ;
                withD[i] = ( withD[i] + withD[i-j] )%prime ;
            }else{

                // cout<<"- from "<<i-j<<" : "<<withoutD[i-j]<<" + "<<withD[i-j]<<"\n";
                withD[i] = ( withD[i] + ( withD[i-j] + withoutD[i-j] ) % prime) % prime ; 
            }        
        }

        // cout<<withoutD[i]<<"\t"<<withD[i]<<"\n";
    }

    cout<<withD[n]<<"\n";

	return 0;
}