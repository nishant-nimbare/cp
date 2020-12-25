// longest Palindrome subsequence
// longest Palindrome substring

#include <bits/stdc++.h>

#define PS <<" - "<<
#define PG <<"  "<<
#define PE <<endl
using namespace std;

int dp[1000][1000];

// time : O n^2 space: O n^2
string longestPalindromicSubsequence(string str){

    int n = str.size();

    memset(dp, 0, sizeof(dp));

    for(int i=0; i<n; i++){
        dp[i][i] = 1;
    
        if((i<n-1) && (str[i] == str[i+1])) dp[i][i+1] = 2;
    }

    for(int gap=2; gap<n; gap++){

        for(int i=0; i<n-gap; i++){

            if( str[i] == str[i+gap] ){

                dp[i][i+gap] = dp[i+1][i+gap-1] + 2 ;
            
            }else{
                dp[i][i+gap] = max( dp[i+1][i+gap], dp[i][i+gap-1] );
            }
        }    
    }


    cout<< dp[0][n-1]<<endl;

    // getting the palindrome
    int i=0, j=n-1;

    stringstream ss;

    while(i <= j){
        if(i==j){
            // only one char remaining
            string temp = ss.str(), rev = temp;

            reverse(rev.begin(), rev.end());
            
            return temp + str[i] + rev;
        }

        if(str[i] == str[j]){

            if( (i+1 )== j){
                // even palindorm centre
                ss<<str[i];
                string temp = ss.str(), rev = temp;

                reverse(rev.begin(), rev.end());
            
                return temp + rev;
            }
        
            ss<<str[i];
            i +=1;
            j -=1;  
        }
        else{

            if(dp[i+1][j] > dp[i][j-1]){
                i +=1;
            }else{
                j -=1;
            }
        }
    }

    return "ERROR";
}



int countSame(int l, int r, string str){

    int res = 0;

    while( (l>=0) && ( r<str.size() ) && (str[l] == str[r])){
        res++;
        l-=1;
        r+=1;
    }

    // cout<<" - "<<l PG r PG res PE;
    return res;
}
// time : O n^2 space: O 1
// there is also dp soln (n^2 time , n^2 space)
string longestPalindromicSubstring(string str){

    // try every element as middle ele and expand on both sides
    int n = str.size();

    int best=1, bestl=0, bestr=0;

    for(int i=0; i<n-1; i++){

        //even
        
        int cur = countSame(i,i, str);
        
        if( best < (2*cur -1 ) ){
            best = 2*cur - 1 ;
            bestl = i -  (cur-1);
            bestr = i +  (cur-1);
        }

        
        if(str[i] == str[i+1]){

            cur = countSame(i, i+1, str);
            
            if( best < 2*cur ){
                best = 2*cur;
                bestl = i   -  (cur-1);
                bestr = i+1 +  (cur-1);
            }
        }
    }


    return str.substr(bestl, bestr - bestl + 1);
}

int main(){

    cout<<longestPalindromicSubsequence("agbdfbkqtja")<<endl;

    cout<<longestPalindromicSubstring("agkbdbkqtja")<<endl;

    return 0;
}