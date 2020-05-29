#include <bits/stdc++.h>
using namespace std;


int isPrime(int a){

    for(int i=2; i<=sqrt(a); i++){
        if(a%i == 0) return i;
    }

    return -1;
}


int main(int argc, char const *argv[]){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int a,b,c;
    cin>>a>>b>>c;
    bool ans=false;


    // if(isPrime(c)==-1){
    //     //c prime
    //     ans=false;
    // }
    // else{
        if(c < min(a,b) ){
            ans=false;            
        }
        else if( (c%a==0) || (c%b==0) || (c%(__gcd(a,b)) == 0) ){
            ans=true;
        }
        else{
            ans = false;
        }
    // }

    if(ans) cout<<"Yes\n";
    else cout<<"No\n";

}