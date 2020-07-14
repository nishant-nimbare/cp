#include <bits/stdc++.h>
using namespace std;

/**
 * 1. find the 1st 2 nos starting from right such that Ai < Ai+1 
 *      
 * 2. Ai needs to be swaped. find a number just greater than Ai in [ Ai+1 ..... An ]
 * 
 * 3. replace Ai with this number
 * 
 * 4, sort [Ai+1 .... An] in ascending order
 * 
 * **/


// binary search
int findJustBig(const string &num, int l, int r, char target){

    while(l<r){
        cout<<" - "<<l<<" "<<r<<"\n";

        int mid = l + (r-l)/2;
        if(num[mid] < target){
            r = mid-1;
        }
        else if(num[mid] > target){
            l = mid+1;
        }
    
    }

    return l-1;
}




int main(int argc, char const *argv[]){

    string num;
    cin>>num;

    int l = num.size()-2, r = num.size()-1; 

    while(l>=0 && num[l]>num[r]){
        r=l;
        l--;
    }

    // here our l is i

    int nxt = r;

    if(num[l] < num[num.size()-1]){
        nxt=num.size()-1;

        // since the nos are decreasing from r to the rightmost
        // if A[i] is smaller than the rightmost (Units digit) than that would be the element just bigger than A[i]
        // as every element in between is bigger than that

    }else{
        // if not we need to find the "just greater" number 

        // optimise with binary search

        // for(; r<num.size(); r++){
        //     if( num[r]>num[l] && num[nxt]>num[r]) nxt=r;
        // }


        nxt = findJustBig(num, r, num.size()-1, num[l]);
    }

    swap(num[l],num[nxt]);

    sort(num.begin()+l+1, num.end() );

    // custom sort in o(n)
    // except 1 element that was swapped everything else is already sorted in decreasing order

    


    cout<<num<<'\n';
}