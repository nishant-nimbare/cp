#include <bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[]){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    while(n--){
        int a,b;
        cin>>a>>b;
        long long int steps=0;
        if(b>a) swap(a,b);

        while(a>0 && b>0){
            steps += a/b;
            a = a%b;

            if( b>a) swap(a,b);            
        }

        cout<<steps<<'\n';
    }
}