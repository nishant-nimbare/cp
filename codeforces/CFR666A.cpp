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

        vector<int> count(26,0);

		 for (int i = 0; i < n; i++) {

			string str;
            cin>>str;

            for( char c : str){
                count[(c-'a')] +=1;
            }
		
		} 

        bool flag = false;
        for(int cnt : count){
            if(cnt%n != 0){
                flag = true;
                break;
            } 
        }

        if(flag) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
	}

	return 0;
}