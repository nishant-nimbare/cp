#include <bits/stdc++.h>

using namespace std;


void printVec(vector<int> v){
	for(auto i:v) cout<<i<<" ";
	cout<<"\n";
}

int mod(int n){
    if(n>=0) return n;

    return (-n);
}

int main(int argc, char const *argv[]){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int t;
	cin>> t;
	
	while(t--){
		int n;
		cin >> n;

		vector<int> arr;

		 for (int i = 0; i < n; i++) {
			int a;
            cin>>a;
            arr.push_back(a);
		} 



		if(arr.size() < 3) {
			printVec(arr);
			continue;
		}

		for(int i=0; i<arr.size(); i++){

			if(i%2==0){
				arr[i] = mod(arr[i]);
			}else{
				arr[i] = -mod(arr[i]);
			}
		}

		printVec(arr);
	}

	return 0;
}