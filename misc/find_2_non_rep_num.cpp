#include <bits/stdc++.h>

#define DEBUG true

#ifdef DEBUG
#define dout cout
#else
#define dout 0 && cout
#endif

using namespace std;

void findTwoNonRepeating( vector<int> arr){

    int mxor = arr[0];

    for(int i=1; i<arr.size(); i++){

        mxor = mxor ^ arr[i] ;
    } 

    // get rightmost set bit
    int mask = mxor & (-mxor);

    cout<<bitset<8> (mxor)<<" "<<bitset<8> (mask)<<endl;

    int setxor=INT_MAX, unsetxor=INT_MAX;
    bool setflag=true, unsetflag=true;

    for(int i=0; i<arr.size(); i++){
        int x= arr[i];

    cout<< " - - "<< bitset<8> ( x & mask ) <<endl;
        
        if( (x & mask) == 0){
            // that bit is not set
            if(unsetflag) {
                unsetxor = x;
                unsetflag = false;
            }else{
                unsetxor = unsetxor ^ x;
            }
        }else{

            if(setflag){
                setxor = x;
                setflag = false;
            }else{
                setxor = setxor ^ x;
            }
        }


    cout<<" - "<< bitset<8> (x) <<" "<<bitset<8> (setxor)<<" "<<bitset<8> (unsetxor)<<endl;


    }

    cout<<setxor<<"  "<<unsetxor<<endl;
}

int main(){
    // vector<int> arr = { };
    findTwoNonRepeating(vector<int> { 2, 3, 7, 9, 11, 2, 3, 11 });
    return 0;
}