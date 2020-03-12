#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <fstream>
#include <numeric>
#include <algorithm>
using namespace std;

// 1
// 10
// B 12
// C 3
// A 6
// D 12
// A 12
// C 6
// A 9
// D 3
// C 12
// A 3



int test(){

    int bits[] = {0,0,1,1};

    // iota(bits,bits+4,0);

    do{
  
        std::cout << "Elements are :"; 
        for (auto i : bits) 
            std::cout << ' ' << i; 
        std::cout << '\n'; 


    }while(next_permutation(bits,bits+4));

    return 0;
}

int main(int argc, char const *argv[])
{
	int t;
	std::fstream myfile("./input.txt", std::ios_base::in);

	myfile>> t;
	int totalProfit=0;

	while(t--){
		int n;
		myfile >> n;

		int table[4][4]={0};

		 for (int i = 0; i < n; i++){

			int time;
			char movie;

			myfile>>movie>>time;

			table[((int)movie - 'A')][(time/3)-1] += 1;

		}

		// cout<<"-----------"<<endl; 

		// for (int i = 0; i < 4; i++){
		// 	for (int j = 0; j < 4; j++)
		// 		cout<<table[i][j]<<'\t';

		// 	cout<<endl;	
		// }
		// cout<<"-----------"<<endl; 
	
        //            A,B,C,D
        int movies[]={0,1,2,3};

        int maxProfit = -1e9;

        do{
            int freq[4];

            for(int i=0;i<4;i++) freq[i] = table[i][movies[i]];
            

            // for (auto i : movies) std::cout << ' ' << i; 
            // std::cout << '\t'; 
            
            // for (auto i : freq) std::cout << ' ' << i; 
            // std::cout << '\n'; 

            sort(freq,freq+4);

            int profit=0;
            for(int i=3;i>=0;i--) profit+=(freq[i]>0)?((i+1)*25*freq[i]):(-100);

            if(profit>maxProfit){
                maxProfit = profit;
                // cout<<" |--max changed "<<maxProfit<<" ";
            }

        }while(next_permutation(movies,movies+4));



		cout<<maxProfit<<endl;
		totalProfit += maxProfit;

	}

	cout<<totalProfit<<endl;

	return 0;
}