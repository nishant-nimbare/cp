#include <bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[]){

    string num;
    cin>>num;
    
    long long int val = stoi(num);
    
    int len = num.size();
    for(int i=0; i< len/2; i++){
        num[len-1-i] = num[i];
    }

    long long int n = stoi(num);

    if(n>=val) {
        cout<<n<<'\n'; 
        return 0;    
    }    

    // n is less

    if((num[len/2]=='9')){
        //round up
        int kstart;
        long long int add=1;

        if(len%2==0) kstart = (len/2) -1;
        else kstart = (len/2);


        for(int k=kstart; k<len; k++){
            num[k]='0';
            add *=10;
        }


        num = to_string( stoi(num) + add);
        cout<<" after rounding up "<<num<<'\n';

        for(int i=0; i< len/2; i++){
            num[len-1-i] = num[i];
        }

        long long int n1 = stoi(num);

        if(n1>=val) {
            cout<<n1<<'\n'; 
            return 0;    
        }        

    }


    if((len%2 == 0) && (num[len/2]!='9')){
        // even digits
        num[len/2] = num[(len/2)-1] = num[(len/2)-1]+1;    
    }else if((len%2 != 0) && (num[len/2]!='9')) {
        num[len/2] += 1; 
    }

    cout<<num<<'\n';
    return 0;

}