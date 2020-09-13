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

	int t;
	cin>> t;
	
	while(t--){
		int a,b;
		cin >> a>>b;

        if(a==b){
            cout<<"0\n";
        }else{
            cout<<((abs(a-b)-1)/10)+1<<"\n"; 
        }
	}

	return 0;
}