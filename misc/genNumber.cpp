#include <bits/stdc++.h>
using namespace std;


int bsearch(int* pref, int msize, int target){

    int lo = 0, hi=msize-1;

    while(lo<hi){
        
        int mid = lo + (hi-lo)/2;
        // cout<<" - mid "<<mid<<"\n";
        if(pref[mid] == target) return mid;

        if(pref[mid]< target) lo = mid + 1;
        else hi = mid;
    }    

    return lo;
}

int main(int argc, char const *argv[]){


    int values[]= {1,2,3};
    int probabilities[] = {25,50,25};

    int msize = sizeof(values)/sizeof(values[0]); 
    
    int pref[msize];

    pref[0] = probabilities[0];
    cout<<" prefix array "<<pref[0]<<" ";

    for(int i=1; i<msize; i++){
        pref[i] = pref[i-1]+ probabilities[i]; 
        cout<<pref[i]<<" ";
    }



    srand(time(NULL));

    int rounds =10;
    while(rounds--){

        int cur = (rand() % pref[msize-1]) +1 ;   // num b/w 1 to last of pref inclusive
        // cout<<" cur "<<cur<<"\n";
        cout<<values[ bsearch(pref, msize, cur) ] <<"\n";

    }

    return 0;
}