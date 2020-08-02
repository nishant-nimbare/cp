#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[]){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int t;
	std::fstream myfile("../input.txt", std::ios_base::in);

	myfile>> t;
	
	while(t--){
		int n,q;
		myfile >> n>>q;

        int Y[n+1];

        for (int i = 1; i <= n; i++) myfile>>Y[i];

        for(int i = 0; i < q; i++){

            int x1,x2,y;
            myfile>>x1>>x2>>y;

            int count =0;

            for(int k=x1+1;k<=x2;k++){

                if( (Y[k-1] <=y && y <= Y[k]) || (Y[k] <=y && y <= Y[k-1]) ) count++;    
            }

            cout<<count<<"\n";
        }

	}

	return 0;
}