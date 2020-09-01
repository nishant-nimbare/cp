#include <bits/stdc++.h>

using namespace std;


void mreverse(string &str, int s, int e){

    int l = e-s+1;
    for(int i=0; i<l/2; i++){
        swap(str[s+i], str[e-i]);
    }
}


void reverseWord(string &str){

    int strlen = str.size();
    mreverse( str, 0, strlen-1);

    // cout<<" str after ini rev :\t "<<str<<'\n';

    for(int k=0; k<str.size(); k++){
        // cout<<" - - "<<k<<'\n';
        if( str[k] == ' ' || k==0){
            int  s=(k==0)?(0):(k+1);
            int  e=s+1;
            
            while ((e < str.size()) && (str[e] != ' ')) e++;

            // cout<<" -  word bet "<<k<<" "<<e<<'\n';
            mreverse(str, s, e-1);

            // cout<<" -  rev..\t "<<str<<'\n';
            k = e-1;
        }
    }

}


int main(int argc, char const *argv[]){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	string t;
	getline( cin , t);

    reverseWord(t);
    cout<<t<<"\n"; 

	return 0;
}