#include <bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[]){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;

    cin>>n>>m;

    // cout<<"n "<<n<<"  m "<<m<<'\n';
    
    int arr[n+1];
    arr[0]=0;
    int c,t;
    for(size_t i=1; i<=n; i++){
        cin>>c>>t;
        arr[i]=arr[i-1]+(c*t);
        // cout<<arr[i]<<' ';
    } 
    // cout<<'\n';

    for(size_t q=0; q<m; q++){
        int query;
        cin>>query;
        bool f=false;

        size_t l=1, r=n, mid;

        while(l<=r){

            mid = l + (r-l)/2;

            if(arr[mid]==query){
                cout<<mid<<'\n';
                f=true;
                break;
            }
            if(l==r){
                if(arr[l]>query){
                    cout<<l<<'\n';
                    f=true;
                    break;
                }else{
                    cout<<(l+1)<<'\n';
                    f=true;
                    break;
                }
            }
            if(arr[mid]<query){
                l=mid+1;
            }else{
                r=mid-1;                
            }
        }

        if(!f){
            cout<<l<<'\n';
        }
        // cout<<"did not find "<<query<<"  "<<l<<" "<<r<<'\n';


    }

}