#include <bits/stdc++.h>
using namespace std;


bool palindrome(int d, int num){

    stringstream ss;

    int day = (num / (24 * 3600))+d; 
  
    num = num % (24 * 3600); 
    int hour = num / 3600; 
  
    num %= 3600; 
    int minutes = num / 60 ; 
  
    num %= 60; 
    int seconds = num;


    ss<<day;
    // num %= 24*60*60;

    ss<< std::setfill('0') << std::setw(2) << hour;
    // num %= 60*60;


    ss<< std::setfill('0') << std::setw(2) << minutes;
    // num %= 60;

    ss<< std::setfill('0') << std::setw(2) << seconds;

    string s = ss.str();
    // cout<<" - checking for "<<s<<"\n";

    int i=0, j=s.size()-1;
    while(i<j){
        if(s[i]!=s[j]) return false;
        i++; j--;
    }

    // cout<<" - found "<<s<<"\n";
    return true;
}

int main(int argc, char const *argv[]){

    int n1,n2;
    cin>>n1>>n2;

    int totalsec = 0;
    int ans =0;
    for(int totalsec=0; totalsec<(n2-n1+1)*(24*60*60); totalsec++){

        if(palindrome(n1, totalsec)){
            ans+=1;
        }

    }


    cout<<ans<<"\n";

}