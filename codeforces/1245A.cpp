#include <bits/stdc++.h>
using namespace std;

// int gcd(int x, int y){
//     if(y==0) return x;
//     else return(y, x%y);
// }


int main(int argc, char const *argv[]){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--){

    int a,b;
    cin>>a>>b;

    if(b>a) swap(a,b);

    if(__gcd(a,b)==1) cout<<"FINITE\n";
    else cout<<"INFINITE\n";

    }

}