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
	// std::fstream myfile("./input.txt", std::ios_base::in);

	cin>> t;
	
	while(t--){
		int n;
		cin >> n;

		string s;
		cin >> s;

		stringstream ss;

		for (int i = 0; i < n; i++) {
			ss<<s[i+i];
		} 

		cout<<ss.str()<<endl;
	}

	return 0;
}