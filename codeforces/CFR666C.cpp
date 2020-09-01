#include <bits/stdc++.h>

#define DEBUG true

#ifdef DEBUG
#define dout cout
#else
#define dout 0 && cout
#endif

using namespace std;


long long int findnum(int ai, int len, int n){

    dout<<" - - "<<ai<<" "<<len<<endl;

    for(long long int mul = 0; mul<INT32_MAX; mul++){

        dout<<" - - - "<<mul<<endl;
    
        if( (ai%n) + ((len*mul)%n) == 0 ){
            return len*mul;
        } 
    }

    return -1;
}

vector<long long int> go(vector<int> &arr, int l, int r){

    dout<<" - "<<l<<" "<<r<<endl;
    
    int len = r-l+1;
    int n = arr.size();

    // add a number to ai such that it is multiple of whole

    vector<long long int> res;
    for(int i=l; i<=r; i++){
        long long int mul = findnum(arr[i], len, n);
        res.push_back(len);
        arr[i] += mul;
    }



    return res;
}

int main(int argc, char const *argv[]){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin>>arr[i];
    } 

    int mid = (n-1)/2;

    vector<long long int> res1 = go(arr, 0, mid);

    cout<<0<<" "<<mid<<endl;
    for(int k: res1) cout<<k<<" ";
    cout<<endl;

    

    vector<long long int> res2 = go(arr, mid+1, n-1);

    cout<<mid+1<<" "<<n-1<<endl;
    for(int k: res2) cout<<k<<" ";
    cout<<endl;

    
    vector<long long int> res3 = go(arr, 0, n-1);

    cout<<0<<" "<<n-1<<endl;
    for(int k: res3) cout<<k<<" ";
    cout<<endl;

    

	return 0;
}