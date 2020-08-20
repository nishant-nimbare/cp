#include <bits/stdc++.h>

using namespace std;

unordered_map<int, long long int> mhash;

long long int factorial(int n){
    if(n<2) return 1;

    return n*factorial(n-1);
}

long long int sterling(int n){
    if( n<=1) return n;

    if( mhash[n] != 0) return mhash[n];

    mhash[n] = (sterling(n-1)*( (2*n)-1)) - ( sterling(n-2)*(n-1)*(n-1) );
    
    return mhash[n]; 
}

int main(int argc, char const *argv[]){

    int n;
    vector<int> nums;

    cin>>n;

    // for(int i=0; i<n; i++){
    //     int a;
    //     cin>>a;

    //     nums.push_back(a);
    // }

    long long int s = sterling(n);
    // cout<<" - "<<s<<"\n"<<factorial(n);

    double ans = (double)s/(double)factorial(n);

    cout.precision(6);
    cout << std::fixed << ans;

}