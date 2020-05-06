#include <bits/stdc++.h>

using namespace std;
const long int mod=998244353;

map <int,long long int> mmap;

long long int raisedTo(int base,long long int exp){
    if(exp==0)return 1;
    if(exp==1)return (base%mod);

    if( (exp&1) != 0) //odd
        return ( (base%mod) * (raisedTo( ( ((base%mod) * (base%mod)) % mod), exp/2) % mod) % mod);

    else //even
        return ( raisedTo( ( (base*base) %mod), exp/2 ) % mod );
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long int n;
    cin >> n;

    mmap[n]=10;

    for (long long int i = n-1; i > 1; i--) {
        
        // long long int ans = ( 18 * (raisedTo(10,n-i)%mod) ) % mod ;
    //    long long int ans= (n-i-1)*9*raisedTo(10,)
        // if(ans<0)
      
        cout<<i<<" "<<ans<<'\n';
        mmap[i]=ans;     
    }

    //1 blocks
    long long int total_digits = ( (n%mod)*(raisedTo(10,n)%mod) )%mod;

    for(auto itr:mmap){
       total_digits = ((total_digits%mod) - ((itr.first*itr.second%mod)%mod)) %mod;
    }

    cout<<"--- ans ---\n"<<1<<"  "<<total_digits<<'\n';

    for(auto itr:mmap) cout<<itr.first<<"  "<<itr.second<<'\n';

    
}