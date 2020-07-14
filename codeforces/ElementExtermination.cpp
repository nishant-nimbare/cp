#include <bits/stdc++.h>
using namespace std;


void printVec(vector<int> v){
	for(auto i:v) cout<<i<<" ";
	cout<<"\n";
}



int main(int argc, char const *argv[]){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int t;
	cin>> t;
	
	while(t--){
		int n;
		cin >> n;

        vector<int> stac;
        for (int i = 0; i < n; i++) {
            int a; cin>>a;

            if(stac.empty()){
                stac.push_back(a);
              
            }
            else{
                bool insert = true;

                while(stac.back() < a){

                    if(stac.size() == 1 ){
                        // dont keep a
                        insert = false;
                        break;
                    }else{
                        stac.pop_back();
                    }

                }

                if(insert) stac.push_back(a);

            }

            // printVec(stac);            
    	} 
 

        if(stac.size() == 1) cout<<"YES\n";
        else cout<<"NO\n";

	}

	return 0;
}