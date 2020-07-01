#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 3 ways partition 
//returns position of 1st pivot and last pivot
pair<int,int> part3(vector<int> &arr, int l, int r){

    int p = arr[l], i=l+1, j=r, k=l+1;
    cout<<" - "<<l<<" "<<r<<"\n";
    cout<<" - - pivot "<<p<<"\n";

    // all elems below i are < p
    // all elems below k are <= p
    // all elems after j are > p

    while(k<=j){
        // cout<<" - "<<k<<" "<<i<<" "<<j<<"\n";
        // for(auto i : arr) cout<<i<<" "; cout<<"\n";

        if(arr[k] > p ) swap(arr[k], arr[j--]);
        else if(arr[k] < p ) swap(arr[k++], arr[i++]);
        else k++;
    }

    swap(arr[l], arr[i-1]);

    return make_pair(i-2,j+1);
}

void quick_sort(vector<int> &arr, int l, int r){

    if(l >= r) return;

    pair<int,int> mids =  part3(arr, l, r);

    if( mids.first > l) quick_sort(arr, l, mids.first);

    if( mids.second < r) quick_sort(arr, mids.second, r);

}

int main(){
    
    vector<int> test = {10,9,11,7,6,5,4,3,2,1};

    for(int k=0; k<test.size(); k++){
        test[k] = ((rand()%100)+test[k])%5 + 1 ;
    }

    
    quick_sort(test, 0, test.size()-1);

    cout<<"\n";  
    for(auto i : test) cout<<i<<" ";

 
    return 0;
}