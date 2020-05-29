#include <bits/stdc++.h>
using namespace std;

unsigned int sieve[3001]; 

int main(int argc, char const *argv[]){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    int count=0;
    fill(sieve,sieve+3001, 0);

    for(size_t i=2; i<=n; i++){

        if(sieve[i]==0){ //this is prime
            
            for(size_t j=i; j<=n; j+=i){
                 sieve[j]+=1;   
            }

        }else{
            if(sieve[i]==2) count++;
        }
    }


    cout<<count<<'\n';

}