#include <bits/stdc++.h>

using namespace std;



bool check(vector<int> &vec){
    
    for(int i=1; i<vec.size(); i++){
        if( vec[i-1] > vec[i]) {
            // cout<<" check true \n";
            return true;
        }
    }

    // cout<<" check false \n";
    return false;
}

int mex(map<int, int> &mmap){

    for(auto p : mmap){
        if(p.second == 0) return p.first;
    }

    // cout<<"MEX NoT FOUND\n";
    return -1;
}


int getNext(vector<int> &steps, int n){

    bool touched[n] = { false };

    for(auto s: steps){
        touched[s] = true;
    }

    for(int i=0; i<n; i++){
        if( touched[i] == false ) return i;
    }


    // cout<<"something went wrong\n";
    return -1;
}


int main(int argc, char const *argv[]){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int t;
	cin>> t;
	
	while(t--){
		int n;
		cin >> n;

        vector<int> arr, steps;
        map<int, int> mmap;

        for (int i = 0; i < n; i++) {
            int a; cin>>a;
            
            if( mmap.count(i) == 0 ) mmap[i]=0;

            arr.push_back(a);
            mmap[a]+=1;

		}

        if( mmap.count(n) == 0 ) mmap[n]=0;

        while(check(arr)){

            int m = mex(mmap);
            // cout<<" mex "<<m<<"\n";
            
            if(m == -1 ) break;

            if(m == n) {
                
                int k = getNext(steps, n);

                if(k == -1) break;

                mmap[arr[k]] -=1;
                arr[k] = m;
                steps.push_back(k);
            
            }else {

                mmap[arr[m]] -=1;
                arr[m] = m;
                steps.push_back(m);
            }

            mmap[m]+=1;
        }

        cout<<steps.size()<<"\n";
        for(auto s: steps) cout<<s+1<<" ";
        cout<<"\n";

	}

	return 0;
}