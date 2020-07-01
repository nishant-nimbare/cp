#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// find min / max element from the unsorted part and append it to the sorted part

void selection_sort(vector<int> &arr){

    for(int i=0; i<arr.size(); i++){

        int  j = i+1, min=i;

        while(j<arr.size()){
            if(arr[j]<arr[min]) min = j;
            j+=1;
        }

        swap(arr[i], arr[min]);
    }
}

int main(){
    
    vector<int> test = {10,9,11,7,6,5,4,3,2,1};

    selection_sort(test);

    for(auto i : test) cout<<i<<" ";
    
    return 0;
}