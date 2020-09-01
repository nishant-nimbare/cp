#include <bits/stdc++.h>

using namespace std;

bool recur(int nums[], int cur, vector<int> buckets, int tar, string prefix){

    prefix = prefix + " ";

    cout<<prefix<<"- "<<cur<<"\n";
    if(cur<0){
        // all elems done
        for(int k : buckets) {
            if(k!= tar) return false;
        }
        return true;
    }


    for(int k=0; k<3; k++){
        
        if( buckets[k] + nums[cur] <= tar ){

            buckets[k] += nums[cur];

            if(recur( nums, cur-1, buckets, tar, prefix)) return true;

        }
    }

    return false;
}

int main(int argc, char const *argv[]){

    int arr[] = { 2, 3, 4, 2, 4, 9, 7, 6, 8, 9};
    // int arr[] ={ 1,1,1};
    vector<int> buckets(3,0);

    int sum =0;

    for(int a: arr){
        sum += a;
    }

    bool ans = recur(arr, 9, buckets, sum/3, "");

    if(ans) cout<<"true\n";
    else cout<<"false\n";
}