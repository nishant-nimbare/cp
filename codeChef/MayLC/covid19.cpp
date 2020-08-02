#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int t;

	cin>> t;
	
	while(t--){
		int n;
		cin >> n;

        int mmax=INT_MIN, mmin=INT_MAX;

        int cur=INT_MIN, prev=INT_MIN, total=-1;

		 for (int i = 0; i < n; i++) {
             prev = cur;
             cin >>cur;
             if( (prev!=INT_MIN) && ((cur-prev)<=2) ){
                 total+=1;
             }else{
                 // group breaks
                if(total!=-1){
                    mmax=max(mmax,total);
                    mmin=min(mmin,total);   
                }
                total=1;
             }
		} 

        // for the last ele        
        mmax=max(mmax,total);
        mmin=min(mmin,total);   

        cout<<mmin<<' '<<mmax<<'\n';
	}

	return 0;
}