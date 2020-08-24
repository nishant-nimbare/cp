#include<iostream>
#include <vector>
using namespace std;


/**
 * 
 * 0 A 1 B 2 C 3 D 4 E 5
 * 
 * 00 01 02 03 04
 * 10 11 12 13 14
 * 20 21 22 23 24
 * 30 31 32 33 34
 * 40 41 42 43 44
 * **/

void printBracket(int left, int right,int size, int * brackets ){
    if( left >= right ) cout<<(char)('A'+left);
    else{
        int b = *((brackets+(left*size)) + right);
        
        if(left<b) cout<<" (";
        printBracket(left, b, size, brackets);
        if(left<b) cout<<") "; 


        if(b+1<right) cout<<" (";
        printBracket( b+1, right, size, brackets);
        if(b+1<right) cout<<")";

    }
}

int chainMul(vector<int> dimensions){

    // N dimension = N-1 matrices
    size_t N = dimensions.size();

    int dp[N-1][N-1];
    int bracket[N-1][N-1];

    for(int i=0; i<N-1; i++) dp[i][i] = 0;

    for(int l=1; l<N-1; l++){

        for(int i=0, j=l; j<N-1; i++, j++ ){

                int left = i, right=j, best=INT32_MAX, bestk=i;

                for(int k=left; k<right; k++){
                
                    int cur =  dp[left][k] + dp[k+1][right] + dimensions[left]*dimensions[right+1]*dimensions[k+1] ;

                    if(cur<best){
                        best = cur;
                        bestk = k;
                    }

                }

                dp[i][j] = best;
                bracket[i][j] = bestk;
        }
    }

    for(int i=0; i<N-1; i++){
        for(int j=0; j<N-1; j++){
            if(j<i) cout<<"\t";
            else cout<<dp[i][j]<<"\t";
        }
        cout<<"\n";
    }

    printBracket(0, N-2, N-1, (int *)bracket);
    cout<<"\n";
    return dp[N-2][N-2];
}


int main(){

    chainMul(vector<int> {10, 20, 30, 40, 30});

    return 0;
}