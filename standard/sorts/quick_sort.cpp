#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int partition(vector<int> &arr, int l, int r, string prefix){

    int pivot = arr[l];

    int k = l+1, j=r;

    while(k<=j){
        if(arr[k]>pivot) swap(arr[k], arr[j--]);
        else k++;
    }

    swap(arr[l], arr[k-1]);

    cout<<prefix;  
    for(int i =l; i<=r; i++) {
        if(i==k) cout<<" | ";
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    
    return k-1;
}

void quick_sort(vector<int> &arr, int l, int r, string prefix){



    if(l<r){

        int m = partition(arr, l, r, prefix);

        quick_sort(arr, l, m-1, prefix+" ");
        quick_sort(arr, m+1, r, prefix+" ");
    }
}



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

void quick_sort3(vector<int> &arr, int l, int r){

    if(l >= r) return;

    pair<int,int> mids =  part3(arr, l, r);

    if( mids.first > l) quick_sort3(arr, l, mids.first);

    if( mids.second < r) quick_sort3(arr, mids.second, r);

}

int main(){

    srand(time(NULL));

    vector<int> test = {10,9,11,7,6,5,4,3,2,1};

    for(int k=0; k<test.size(); k++){
        test[k] = ((rand()%100)+test[k])%50 + 1 ;
    }

    
    quick_sort(test, 0, test.size()-1,"");

    cout<<"ANS\n";  
    for(auto i : test) cout<<i<<" ";

 
    return 0;
}