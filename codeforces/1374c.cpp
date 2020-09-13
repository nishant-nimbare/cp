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
        string str;
        cin>>str;

        vector<int> stac;
        int ob=0, ans=0;

        for (int i = 0; i < n; i++) {	
            if(str[i] == '(') ob+=1;
            if(str[i] == ')'){
                if(ob>0) ob-=1;
                else ans+=1;
            }  
		} 

        cout<<ans<<endl;
	}

	return 0;
}