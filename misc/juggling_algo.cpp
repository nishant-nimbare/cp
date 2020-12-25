#include <bits/stdc++.h>

using namespace std;

// juggling Algo

void printVec(vector<int> a){ for(auto x:a) cout<<x<<" "; cout<<endl;}
 
void rotate(vector<int> &arr, int k){
    int n = arr.size();
    for(int i=0; i<__gcd(n,k); i++){

        int j=i;
        int temp = arr[j];
        
        int d;
        while(1){
            d= (j+k)%n;
            if(d==i) break;
            arr[j] = arr[d];
            j = d;
        }

        arr[j] = temp;
        printVec(arr);
    }

}

int main(){
    int k=3;
    vector<int> arr = {1,2,3,4,5,6};
    
    rotate(arr, k);
    cout<<" ANS : ";
    printVec(arr);
    return 0;
}