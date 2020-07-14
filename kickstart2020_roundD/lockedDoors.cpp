#include <bits/stdc++.h>
using namespace std;


int naive(vector<int> &doors, int s, int k){
    int tr = doors.size()+1;
    int l = (s>0)?(s-1):(-1);
    int r = (s<tr-1)?(s):(-1);

    // cout<<" s "<<s<<"\n";
    int cur = s;
    while(k--){

        // cout<<" - "<<l<<" "<<r<<" "<<cur<<"\n";

        if(r==-1 && l==-1)break;//cout<<" l and r -ve "<<cur<<"\n";

        if(l==-1){
            // cout<<" going right\n";
            cur =r+1;
            r +=1;
            continue;
        }

        if(r==-1 || doors[l]<doors[r]){
            // go left
            // cout<<" going left\n";
            cur =l;
            l-=1;  
        }
        else{
            // go right
            // cout<<" going right\n";
            cur =r+1;
            r +=1;
        }

        if(l<0) l=-1;
        if(r>=doors.size()) r=-1;
    } 

    return (cur+1);
}

int main(int argc, char const *argv[]){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int tests;
	cin>> tests;
	
	for( int t = 1; t <= tests; t++) {
		int N,Q;
		cin>>N>>Q;

        vector<int> door;
		for (int i = 0; i < N-1; i++) {
			int a; cin>>a;
            door.push_back(a);
		} 

        vector<int> ans;

        for(int q=0; q<Q; q++){
            int s,k;
            cin>>s>>k;

            ans.push_back(naive(door, s-1,k-1));
        }

        cout<<"Case #"<<t<<": ";
        for(auto a:ans)cout<<a<<" ";
        cout<<"\n";
	}

	return 0;
}