#include <bits/stdc++.h>

#define DEBUG true

#ifdef DEBUG
#define dout cout
#else
#define dout 0 && cout
#endif

using namespace std;


int maxNumKSwaps(int num, int k){
    string  str = to_string(num);
    int l=0;

    while( (k>0) && ( l<str.size() ) ){
        // find max number in 1st k ele
        // bring it to left
    
        int maxele = str[l], maxidx = l;

        for(int i=l; i<=(k+l); i++){ 

            if(str[i] > maxele){
                maxidx = i;
                maxele = str[i];
            }
            cout<<" - "<<(char)maxele<<" ( "<<maxidx<<" )   ";
        }


        while((maxidx>l) && (k>0)){
            swap(str[maxidx], str[maxidx-1]);
            maxidx--;
            k--;
        }

        l++;
        cout<<" - - "<<str<<" "<<k<<endl;
    }

    int ans;
    istringstream (str) >> ans;
    return ans;
}

int main ( ){

    cout<<maxNumKSwaps( 25879, 2)<<endl;

    return 0;
}