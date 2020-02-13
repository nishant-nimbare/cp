#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <fstream>
using namespace std;

struct ret{
	int maxNo,i,j;
};

typedef struct ret Struct;

Struct findMax(int table[4][4]){
	Struct s;


	s.maxNo = 0;
	s.i=0;
	s.j=0;

	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){

			if(table[i][j]>s.maxNo){
				s.maxNo = table[i][j];
				s.i = i;
				s.j = j;
			}			
		}
	}

	return s;
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


		int profit = 0;

		for (int k = 4; k >= 1; k--)
		{
			Struct s  = findMax(table);
			
			if(s.maxNo == 0 ){
				profit -= 100;
			}else{
				profit += (k*25)*s.maxNo;
			}

			for(int itr=0; itr < 4 ; itr++){
				table[s.i][itr] = -1;
				table[itr][s.j] = -1;
			}

		}
		
		cout<<" profit  "<<profit<<endl;
		totalProfit += profit;

	}

	cout<<totalProfit;

	return 0;
}