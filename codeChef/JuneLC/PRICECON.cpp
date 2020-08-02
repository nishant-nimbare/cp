#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int t;
	// std::fstream myfile("./input.txt", std::ios_base::in);

	cin>> t;
	while(t--){
		int n,k;
		cin >> n>>k;
        int result = 0;

		 for (int i = 0; i < n; i++) {
			int p;
			cin>>p;
            result+=max(0, p-k);
		} 

    cout<<result<<"\n";    
	}

	return 0;
}