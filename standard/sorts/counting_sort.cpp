#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// https://www.youtube.com/watch?v=1mh2vilbZMg&t=362s


vector<int> countingSort(vector<int> &arr){

    int k = * max_element(arr.begin(), arr.end());
    k+=1;

    vector<int> count(k, 0);

    for(int i=0; i<arr.size(); i++){
        count[arr[i]]+=1;
    }


    // make running sum array from count

    for(int i=1; i<count.size(); i++){
        count[i]+=count[i-1];
    }

    vector<int> sorted(arr.size());

    for(int i=0; i<arr.size(); i++){

        if( count[ arr[i] ] <= 0 ) continue;
        
        sorted[ count[arr[i]] - 1 ] = arr[i];
        count[ arr[i] ] -= 1;
    }

    return sorted;    
}


int main (){

    size_t len = 23;
    srand(time(NULL));
    vector<int> arr;

    for (int i = 0; i < len; i++){
        arr.push_back(rand()%20);
    }

    cout<<" arr before ------------- "<<endl;
    for(int val : arr) cout<<val<<" ";
    cout<<endl;

    vector<int> sorted = countingSort(arr);

    cout<<" arr after --------------- "<<endl;
    for(int val : sorted) cout<<val<<" ";
    cout<<endl;


    return 0;
}
