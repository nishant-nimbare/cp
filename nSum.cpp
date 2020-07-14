#include <bits/stdc++.h>
using namespace std;

vector< pair<int, int> > twoSum(vector<int> &arr, int left, int right, int tar){

    vector< pair<int, int> > ans;

    int l=left, r=right;

    while(l<r){

        if(arr[l]+arr[r] == tar) {
            ans.push_back({arr[l],arr[r]});
            
            do { l+=1; } while( arr[l]==arr[l-1] && l<r) ;

            do { r-=1; } while( arr[r]==arr[r+1] && l<r) ;
                
        }
        else if(arr[l]+arr[r] > tar){
            r-=1;
        }
        else{
            l+=1;
        }
    }

    return ans;
}


vector< vector<int> > nSum(vector<int> &arr, int l, int r, int tar, int n){

    vector< vector<int> > ans ;

    if(n<2) return ans;

    if(n==2){
        vector<pair<int,int >> res = twoSum(arr,l,r,tar);
        for(auto p: res){
            ans.push_back(vector<int> {p.first, p.second});
        }
        return ans;
    }


    for(int i=l; i<r; i++){

        if(i>l && arr[i-1] == arr[i] ) continue; // dont consider duplicate

        // if( ( tar < (n-1)*arr[i+1] ) || ( tar > (n-1)*arr[r] ) ) break;

        vector< vector<int> > res = nSum( arr, i+1, r, (tar-arr[i]), n-1 );

        for(auto v: res){
            vector<int> temp = { arr[i] };
            temp.insert(temp.end(), v.begin(), v.end());
            ans.push_back(temp);
        }
    }

    return ans;
}



int main(int argc, char const *argv[]){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> arr = {-2, 0, 0, 2, 2};
    
    sort(arr.begin(), arr.end());

    // vector<int>::iterator ip = unique(arr.begin(), arr.end());

    // arr.resize( std::distance(arr.begin(), ip) );

    vector<vector<int>> ans = nSum(arr,0, arr.size()-1, 0, 3);

    for(auto vec: ans){
        
        for(auto i: vec) cout<<i<<" ";

        cout<<"\n";
    }

	return 0;
}