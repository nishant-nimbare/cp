#include <iostream>

using namespace std;

int main(){

    int n;
    cin>>n;

    if(n == 1) cout<<2;
    else{
        unsigned long long int ans = 0;
        unsigned long long cur = 1;
        for(int i=1; i<=n; i++){
            cur *= 2;
            ans += cur;
        }

        cout<<ans;
    }


    return 0;
}
