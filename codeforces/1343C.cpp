#include <bits/stdc++.h>
using namespace std;

bool getSign(int num){
    if(num>0) return true;
    return false;
}

int main(int argc, char const *argv[]){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int t;
	// std::fstream myfile("./input.txt", std::ios_base::in);

	cin>> t;
	
	while(t--){
		int n;
		cin >> n;

        int arr[n];

		 for (int i = 0; i < n; i++) {
             cin>>arr[i];
		}

        bool sign = getSign(arr[0]);
        long long int sum = arr[0];
        int last = arr[0];
        for(size_t i=1; i<n; i++){
            
            // cout<<arr[i]<<" last:"<<last<<" sum:"<<sum<<'\n';

            if(getSign(arr[i]) == sign){
                //next num is same as last 

                if(arr[i]>last){
                    // better num than last
                    sum-=last;
                    sum+=arr[i];
                    last=arr[i];
                }

            }else{
                //next num is different
                sum+=arr[i];
                last=arr[i];
                sign = !sign;                
            }
        }


        cout<<sum<<'\n';

	}

	return 0;
}