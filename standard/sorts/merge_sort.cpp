#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


// recursive divide array and merge 


void merge(vector<int> &arr, int l, int mid, int r){

    int temp[r-l+1];

    int i=l, j=mid+1, k=0;

    while(i<=mid && j<=r){

        if(arr[i]<arr[j]) {temp[k++] = arr[i++]; /* i++; */ }
        else {temp[k++] = arr[j++]; /* j++;*/}
    
        // k++;
    }

    while(i<=mid){
        temp[k++] = arr[i++];
        // k+=1;
        // i+=1;
    }


    while(j<=r){
        temp[k++] = arr[j++];
        // k+=1;
        // j+=1;
    }

    for(int t=l; t<=r; t++){
        arr[t] = temp[t-l];
    }

}


void merge_sort(vector<int> &arr, int l, int r){


    if(l<r){
        int mid = l + (r-l)/2;

        merge_sort(arr, l, mid);
        merge_sort(arr, mid+1, r);
    
        merge(arr, l, mid, r);
    }

}



int main(){
    
    vector<int> test = {10,9,11,7,6,5,4,3,2,1};

    for(int k=0; k<test.size(); k++){
        test[k] = (rand()%100)+test[k];
    }

    merge_sort(test, 0, test.size()-1);

    for(auto i : test) cout<<i<<" ";
    
    return 0;
}