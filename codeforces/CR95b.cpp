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
		int n;
		cin >> n;

        vector<int> arr, lock;

        for (int i = 0; i < n; i++) {
			int a; cin>>a;
            arr.push_back(a);
		} 


        for (int i = 0; i < n; i++) {
			int a; cin>>a;
            lock.push_back(a);
		} 


        for(int i=0; i<n; i++){

            if(lock[i] == 1) continue;

            int min = i;
            for(int j=i+1; j<n; j++){

                if(lock[j]==0 && arr[min]>arr[j]) min=j;
            }

            swap(arr[i], arr[min]);
        }

        for(int i:arr){
            cout<<i<<" ";
        }
        cout<<"\n";
        
	}

	return 0;
}