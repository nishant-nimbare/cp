#include <bits/stdc++.h>

using namespace std;

// vector<int> arr;
// vector<int> zero;
// vector<int> two;

// int getNextZero(int i){
// 	int index=0;
// 	while(index<zero.size() && zero[index]<=i) index++;
// 	return index;
// }


int main(int argc, char const *argv[]){

	// ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

	int t;
	cin>> t;
	
	while(t--){

		// arr.clear();
		// zero.clear();
		// two.clear();
		

		int n;
		cin >> n;

		int arr[n]={0};
		int temp;

		for (int i = 0; i < n; i++) {
			cin>>temp;
			temp=temp%4;

			// cout<<" in "<<temp<<'\n';
			// if(temp==0) zero.push_back(i);
			// else if(temp==2) two.push_back(i);

			// arr.push_back(temp);
			arr[i]=temp;

		} 

		int nextZero[n]={-1};
		int c0=n;
		for(int i=n-1;i>=0;i--){
			nextZero[i] = c0;
			// cout<<" next z of "<<i<<" = "<<c0;
			if(arr[i]==0) c0=i;
		}

		// cout<<"next zero array ";
		// for(auto k:nextZero) cout<<" "<<k;
		// cout<<"\n\n\n";

		int l=-1,f=0;
		int l2=-1,l0=-1; // last two and last zero;
		int ll2=-1; 

		long long int ans =0;

		while (f<n){

			if(arr[f] == 2){
				
				// 1 & 3 s in between l2 and f
				int c = (f-1-l2);
				ans += (c*(c+1))/2;

				if(l2 != ll2 ){
					//the second 2;
					int n0 = nextZero[f];

					// elements b/w  ll2 and l2
					int lc = (l2-1-ll2);

					// elements b/w f and n0
					int rc = ( n0 -1 -f);
				
					ans+= (lc*rc) + lc + rc + 1;	

				}

				ll2=l2;
				l2=f;
			}
			else if(arr[f] == 0 ){

				// 1 & 3 s in between l2 and f
				int c = (f-1-l2);
				ans += (c*(c+1))/2;

				int lc = (f-1-l0);
				int rc = (n-1-f);

				ans+= (lc*rc) + lc + rc + 1;	

				l0=f;
				ll2=l2=f;			
			}

			if(f==(n-1)){
				//last element reached
				int c = (f-l2);
				ans += (c*(c+1))/2;
			}


			f++;
			// cout<<f<<"th iteration, ans = "<<ans<<'\n';
		}
		

		// cout<<" ---------- final ans = "<<ans<<" -------- \n\n";
		cout<<ans<<'\n';
	}

	return 0;
}