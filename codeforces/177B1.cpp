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

    int n;
    cin>>n;

    unsigned long long int ans = n;

    while(n>1){

        int fact = isPrime(n);
        // cout<<" - - prime "<<fact<<"\n";
        if( fact == -1){
            // we can make any smaller rect
            // all rows with 1
            ans+=1;
            n=1;
            break;
        }

        // we will have fact number of rows
        n = n/fact;
        ans+=n;
        // cout<<" - n "<<n<<" ans "<<ans<<"\n";
    }

    cout<<ans<<'\n';
}