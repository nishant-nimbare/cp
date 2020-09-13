#include <bits/stdc++.h>

using namespace std;

void print(int a[3], int b[3]){

    for(int i=0;i<3;i++) cout<<a[i]<<" ";
    cout<<endl;
    for(int i=0;i<3;i++) cout<<b[i]<<" ";
    cout<<endl;

}

int main(){
    int t;
    cin>>t;

    while(t--){

        int a[] = {0,0,0};
        int b[] = {0,0,0};

        for(int i=0;i<3;i++) cin>>a[i];
        for(int i=0;i<3;i++) cin>>b[i];

        long int ans = 0, t;
        
        ans += 2*min(a[2],b[1]);
        a[2] -= min(a[2],b[1]); 
        b[1] -= min(a[2],b[1]);

        // print(a,b);

        if(a[2]>0){
            t = min(a[2],b[2]);
            a[2] -= t;
            b[2] -= t; 
            
            // print(a,b);
        }

        t = min(a[0],b[2]);
        b[2] -= t;
        a[0] -= t;
            
        // print(a,b);


        if(b[2]>0){
            ans -= 2*b[2];
            a[1] -= b[2];     
            // print(a,b);

        }

        cout<<ans<<endl;

    }
}