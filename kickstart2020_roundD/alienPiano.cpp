#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int tests;

	cin>> tests;
	
	for( int t = 1; t <= tests; t++) {
		int n;
		cin >> n;

        vector<int> arr;
		for (int i = 0; i < n; i++) {
			int a; cin>>a;
            if( arr.size()==0 || ( a != arr.back() ) ) arr.push_back(a);
		} 

        // cout<<arr.size()<<" size \n";

        unordered_set<int> minima, maxima;

        for(int i =0; i<arr.size(); i++){
            
            if( ( ( i==0 || arr[i-1] < arr[i] )  && ( i==n-1 || arr[i] > arr[i+1] ) ) )
            {
                maxima.insert(i);
            }
            else if( ( (i==0 || arr[i-1] > arr[i])  && (i==n-1 || arr[i] < arr[i+1] ) )  )
            {
                minima.insert(i);
            }
        
        }


        int faults=0, lmin=INT32_MIN, lmax=INT32_MIN;

        for(int i =0; i<arr.size(); i++){

            if(minima.count(i)==1){

                // cout<<" min : "<<i<<" "<<lmin<<" "<<lmax<<"\n";

                if( lmin == i-1 ) lmax = -1;

                lmin=i;
                
                if(lmax!=-1 && (lmin - lmax)>3 ){
                    //FAULT     
                    faults += (lmin-lmax)/4;
                }

            }else if(maxima.count(i)==1){

                // cout<<" max : "<<i<<" "<<lmin<<" "<<lmax<<"\n";

                if( lmax == i-1 ) lmin = -1;

                lmax=i;
                if( lmin!=-1 && (lmax - lmin)>3 ){
                    //FAULT
                    faults += (lmax-lmin)/4;                
                }
            }
        }

        cout<<"Case #"<<t<<": "<<faults<<"\n";
	}

	return 0;
}