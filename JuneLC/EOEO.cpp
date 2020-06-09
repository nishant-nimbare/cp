#include <bits/stdc++.h>
#define lli long long int
using namespace std;

int main(int argc, char const *argv[]){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int t;
	cin>> t;
	
	while(t--){
		lli n;
		cin >> n;

		if(n%2 == 1){
        
            cout<<(n-1)/2<<"\n";
        
        }else{

            lli factor=1;

            while (n%2==0){
                n /= 2;
                factor *= 2; 
            }

            cout<<(n-1)/2<<"\n";
        }
	}

	return 0;
}