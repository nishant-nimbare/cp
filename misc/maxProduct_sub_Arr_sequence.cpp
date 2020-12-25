// Max Product subArray
// Max Product subsequence

#include <bits/stdc++.h>

#define DEBUG true

#ifdef DEBUG
#define dout cout
#else
#define dout 0 && cout
#endif

#define PS <<" - "<<
#define PG <<"  "<<
#define PE <<endl

using namespace std;

// very similar to kadane's
int maxProductSubarray(vector<int> arr){

    int local_max= arr[0], local_min = arr[0], global_max=arr[0];

    int left1 = 0, left2  = 0, right = 0, bestl1=0, bestl2, bestr=0;

    for(int i=1; i<arr.size(); i++){
        int c1 = local_max*arr[i];
        int c2 = local_min*arr[i];
    
        local_max = max(c1, c2);
        local_min = min(c1, c2);

        // local_max = max(local_max, arr[i]);

        if(local_max < arr[i]){
            left1 = i;
            local_max = arr[i];
        }

        if(local_min > arr[i]){
            left2 = i;
            local_min = arr[i];
        }

        right = i;

        // global_max = max(global_max ,local_max);
    
        if( global_max < local_max){
            bestl1 = left1;
            bestl2 = left2;
            bestr = right;
           global_max = local_max;
        }
    }


    for(int i=bestl1; i<=bestr; i++) cout<<arr[i]<<", "; cout PE;


    for(int i=bestl2; i<=bestr; i++) cout<<arr[i]<<", "; cout PE;


    return global_max;
}

int main(){

    cout<<maxProductSubarray(vector<int> {-2, -3, 0, -2, -40}) PE;

    return 0;
}