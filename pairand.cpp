#include <iostream>
#include <bits/stdc++.h>
#include <map>
#include <vector>
using namespace std;

int main() {
    
    int t,ans=0,max=0;
    cin >> t;
    int bits[100]={0};
    
    while(t--){
        
        int n,i=0;
        cin >>n;
        
        while(n>0){
            if((n&1)==1) bits[i]+=1;
            n = n>>1;
            i++;
            if(i>max) max=i;
        }
        
    }
    
    for (int i = 0; i <= max; i++) {
        
        if(bits[i]>0)
        ans += (int)( ( bits[i] * ( bits[i]-1 ) ) / 2) * (1<<i); 
    }

    cout<<ans<<endl;
	return 0;
}

