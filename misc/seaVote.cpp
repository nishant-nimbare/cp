// https://www.codechef.com/problems/SEAVOTE

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <fstream>
using namespace std;

// inputs
// 3
// 3
// 30 30 30
// 4
// 25 25 25 25
// 2
// 50 51

int main(int argc, char const *argv[])
{
	int t;
	std::fstream myfile("./input.txt", std::ios_base::in);

	myfile>> t;
	
	while(t--){
		int n,total=0;
		myfile >> n;

		int num = n;

		while(n--){

			int a;
			myfile >>a;

			total += a;
			if(a == 0) num--;
		} 
		cout<<"total "<<total<<endl;

		if(total < 100){
			cout<<"NO"<<endl;
			continue;
		}


		if(total == 100){
			cout<<"YES"<<endl;
			continue;
		}

		if(total > 100){
			
			// cout<<"total >100 "<<total<<"  n  "<<num<<endl;

			if(total<num+100){
				// cout<<"total >100 "<<total-100<<endl;
			
				cout<<"YES"<<endl;
		
			}else{
				cout<<"NO"<<endl;			
			}
		}

	}

	return 0;
}