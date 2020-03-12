#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;


int solve(int a,int b,int c){

    //ca and cb are current water lvls in and b respectively
    //initially fill a and keep b empty 
    int ca=a,cb=0,moves=1,transfer;

    // in each iteration we transfer water from a to b
    // amount transfered is  either the capacity left in b or the whole amount in a

    while(ca!=c && cb!=c){

        transfer=min(ca,b-cb);
        ca-=transfer;
        cb+=transfer;
        moves++;

        if(ca==c || cb==c){
            //got c
            return moves;
        }

        if(ca==0){
            // fill a  if empty
            ca=a;
            moves++;
        }

        if(cb==b){
            // empty b if full
            cb=0;
            moves++;
        }
    }

    return moves;

}

int main(int argc, char const *argv[])
{
	int t;
	std::fstream myfile("./input.txt", std::ios_base::in);

	myfile>> t;
	
	while(t--){
		int a,b,c;
		myfile>>a>>b>>c;

        if(c>max(a,b) || (c%__gcd(a,b)!=0) ){
            cout<<-1<<endl;
            continue;   
        }

        // int high = max(a,b);
        // int low = min(a,b);
        // int ans=-1;

        // if(c%low == 0){
            
        //     ans=(c/low)*2;

        // }else if( (high-c)%low ==0 ){
            
        //     ans=((high-c)/low)*2;
        
        // }


        if(a==c || b==c ) {
            cout<<1<<endl;
            continue;
        }

        // min(solve(a,b,c),solve(b,a,c));        


        cout<<min(solve(a,b,c),solve(b,a,c))<<endl;

	}

	return 0;
}