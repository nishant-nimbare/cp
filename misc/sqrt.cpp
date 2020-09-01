#include <bits/stdc++.h>
using namespace std;

int sqrt(int num){

    int l=1, h=num/2+1;

    while(l+1<h){
        int mid = l + (h-l)/2;

        if(mid*mid == num){
            return mid;
        }

        if(mid*mid < num){
            l = mid;
        }else{
            h = mid;
        }
    }

    return l;
}



int main(int argc, char const *argv[]){

    int num;
    cin>>num;

    cout<<sqrt(num)<<'\n';
}