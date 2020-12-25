#include <bits/stdc++.h>
using namespace std;

int mpow(int n, int e){

    if(e==0) return 1;

    if(e==1) return n;

    if(e%2==1){
        return mpow(n*n, e/2) * mpow(n,1);
    }else{
        return mpow(n*n, e/2);
    }

}

int mlog(int n, int base){
    return (log(n)/log(base));
}

void bucketSort(vector<int> &arr){

    int mmax = *max_element(arr.begin(), arr.end());

    int x = mlog(mmax, 10);
    vector<vector<int>> buckets(mpow(10, x), vector<int>{});

    cout<<mmax<<" "<<x<<" "<<buckets.size()<<endl;

    for(int i=0; i<arr.size(); i++){
        buckets[arr[i]/10].push_back(arr[i]);
    }

    for(int b=0; b<buckets.size(); b++){
        sort(buckets[b].begin(), buckets[b].end());
    }

    arr.clear();
    for(int b=0; b<buckets.size(); b++){
        cout<< b << " -> ";
        for(int n: buckets[b]) {
            arr.push_back(n);
            cout<<n<<"  ";
        }
        cout<<endl;
    }
}

int main(){

    vector<int> arr = {17, 45, 75, 90, 3, 24, 2, 66, 61, 13, 77, 71, 25};

    bucketSort(arr);
    cout<<endl<<"ans "<<endl;
    for(int n: arr) cout<<n<<" ";
    cout<<endl;
    return 0;
}