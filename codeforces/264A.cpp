#include <bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cin >> str;

    vector<int> left, right;

    for(int i=0;i<str.length();i++){

        if(str[i]=='l') left.push_back(i+1);
        else right.push_back(i+1);

    }

    for(int r:right) cout<<r<<'\n';

    for(int l=left.size()-1; l>=0; l--) cout<<left[l]<<'\n';
}
