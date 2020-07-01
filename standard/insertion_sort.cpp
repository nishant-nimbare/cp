#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// card sorting algo
// get next element from the unsorted part and bring it to its relatively correct position


void insertion_sort(vector<int> &arr){

    for(int i=1; i<arr.size(); i++){

        int k = i, j = i-1;

        while(k>0 && arr[j]> arr[k]){
            std::swap(arr[k], arr[j]);
            k--;
            j=k-1;
        }
    }
}

int main(){
    
    vector<int> test = {10,9,11,7,6,5,4,3,2,1};

    insertion_sort(test);

    for(auto i : test) cout<<i<<" ";
    
    return 0;
}