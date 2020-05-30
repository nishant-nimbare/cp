#include <bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[]){

    string num;
    cin>>num;

    int l = num.size()-2, r = num.size()-1; 
    while(l>=0 && num[l]>num[r]){
        r=l;
        l--;
    }

    int nxt = r;
    for(; r<num.size(); r++){
        if( num[r]>num[l] && num[nxt]>num[r]) nxt=r;
    }

    swap(num[l],num[nxt]);

    sort(num.begin()+l+1, num.end() );

    cout<<num<<'\n';
}