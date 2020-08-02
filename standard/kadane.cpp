#include <bits/stdc++.h>

#define DEBUG true

#ifdef DEBUG
#define dout cout
#else
#define dout 0 && cout
#endif

using namespace std;



int kadane(vector<int> arr){

    if(arr.empty()) return 0;

    int global_max, local_max;

    global_max = local_max = arr[0]; 

    for(int i=1; i<arr.size(); i++){

        local_max = max(local_max+arr[i], arr[i]);

        global_max = max(global_max, local_max);
    }

    return global_max;
}

int main(int argc, char const *argv[]){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<kadane(vector<int> {-2,1,-3,4,-1,2,1,-5,4})<<"\n";
}