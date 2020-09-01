#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){
	
	int t;
	cin>>t;
	while(t--){
		long long int n,k,i;
		long long int a=1ll;
		cin>>n>>k;

		if(k>n/2) k = n-k;

		for (i = 1ll; i <= k; i++)
		{
			a = a*((n--)/i);
			// n=n-1;
		}

		cout<<a<<endl;
	}
	return 0;
}
