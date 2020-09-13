#include <bits/stdc++.h>

#define DEBUG true

#ifdef DEBUG
#define dout cout
#else
#define dout 0 && cout
#endif

using namespace std;

int go(int a, int b){
    if(a==0 || b==0) return 0;

    if(a==b) return (2*a)/3;

    if(a>b) return go(b,a);

    if(a<(b-a)) return a;

    return (b-a)+go(a-(b-a), b-(2*(b-a)));

}

int main(int argc, char const *argv[]){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int t;
	cin>> t;
	
	while(t--){
		int a, b;
		cin >> a>>b;

        cout<<go(a,b)<<endl;
	}

	return 0;
}