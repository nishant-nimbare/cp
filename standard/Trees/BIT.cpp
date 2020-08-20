#include <bits/stdc++.h>
using namespace std;



/**
 * Get Next :
 * 1. 2's compliment of index
 * 2. And (&) it with index
 * 3. add the original index
 * 
 * Get Parent:
 * 1. 2's comp of index
 * 2. And (&) it with index
 * 3. subtract it from index
 *  
**/



vector<int> BIT;
vector<int> original;

void updateUtil(int idx, int val){

    for(int i = idx+1; i<BIT.size(); i += (i&(-i)) ){
        BIT[i] += val;
    }

}

void BitInit(vector<int> arr){

    original = arr;
    
    BIT.clear();
    BIT.resize(arr.size()+1, 0);

    for(int i=0; i<arr.size(); i++){
        updateUtil(i, arr[i]);
    }

    cout<<" Original : ";
    for(int k:original) cout<<k<<" ";
    cout<<endl;

    cout<<" Bit : ";
    for(int k:BIT) cout<<k<<" ";
    cout<<endl;
    

}

void BitUpdate(int index, int value){

    cout<<" - - updating "<<index<<" "<<value - original[index]<<endl;
    updateUtil(index, value - original[index]);
    original[index] = value;

}

int BITSum(int idx){
    int res = 0;

    for(int i = idx+1; i>0; i -= (i&(-i)) ){
        // cout<<" - - - "<<i<<endl;
        res += BIT[i];
    }

    // cout<<"return sum "<<res<<endl;
    return res;
}

int BITquery( int left, int right){

    // cout<<" - - querying "<<left<<" "<<right<<endl;
    if(left == 0 ) return BITSum(right);
    
    return BITSum(right) - BITSum(left-1); 
}


int main(){

    int n; cin>>n;
    vector<int> arr;

    while(n--){
        int t; cin>>t;
        arr.push_back(t);
    }

    BitInit(arr);


    cout<<" total : "<<BITSum(arr.size()-1)<<endl;

    int q; cin>>q;
    vector<int> results;
    while(q--){
        char c;
        int a, b;
        cin>>c>>a>>b;

        if(c == 'u'){
            BitUpdate(a, b);
        }else{
            results.push_back( BITquery(a, b) );
        }
    }

    cout<<" answers : ";
    for(int a:results) cout<<a<<" ";
    cout<<endl;
}