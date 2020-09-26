#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main(int argc, char const *argv[]){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int t;
	cin>> t;
	
	while(t--){
		int n;
		cin >> n;

        vector<int> arr;

        bool f = false;
        int prev = -1;
        for (int i = 0; i < n; i++) {

			int a; cin>>a;

            
            if(prev==-1 || f){ 
                prev = a;
                continue;
            }

            if(a>=prev){
                f =true;
            }

            prev = a;
            arr.push_back(a);
		} 

        cout<< ( ( f ) ? ("YES"):("NO") ) <<endl;
	}

	return 0;
}