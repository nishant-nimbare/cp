#include <bits/stdc++.h>

#define DEBUG true

#ifdef DEBUG
#define dout cout
#else
#define dout 0 && cout
#endif

using namespace std;


int main(int argc, char const *argv[]){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin>>arr[i];
    } 

    sort(arr.begin(), arr.end());

    int c = round( pow(arr[n-1], 1.0/(n-1)) );

    // dout<<" - c "<<c<<endl;

    long long int ans=0;
    long long int cur = 1;
    for (int i = 0; i < n; i++) {
        ans+= abs(arr[i] - cur);
        cur = cur*c;
    } 

    cout<<ans<<endl;

	return 0;
}