// https://www.codechef.com/problems/NUMFACT

#include <iostream>
#include <bits/stdc++.h>
#include <map>
#include <fstream>
#include <vector>
using namespace std; 

// input
// 3
// 3
// 3 5 7
// 3
// 2 4 6
// 2
// 5 5

int MAX = 1000000;

std::map<int, map<int,int>> mhash;

std::vector<int> least(MAX+1,0);


void calcLeast(){

	// cout<<" calcLeast "<<endl;

	least[1] = 1;

	for (int i = 2; i < MAX+1; ++i)
	{
		if(least[i] == 0){ 
			for (int j = i; j <MAX+1 ; j=j+i)
			{
				// cout<<i<<" "<<j<<endl;

				if(least[j] == 0)least[j] = i;
			}
		}
	}


	// for (int i = 0; i < 10; ++i)
	// {
	// 	cout<<least[i]<< "  ";
	// }
	// cout<<endl;
}

void printIt(map<int,int> &m) {
    
    for (auto itr = m.begin(); itr != m.end(); ++itr) { 

 		std::cout << itr->first << ":" << itr->second << " ";
 	}

        
    std::cout << std::endl;
}


void push(map<int,int> &m,int key,int val){

	// cout<< " pushing ...." <<key<<endl;	
	
	std::map<int , int>::iterator it;
	
	it = m.find(key);

	if (it != m.end()) it->second += val ;
    else m.insert({key,val});

}

void getFactors(map<int,int> &m,int k){



	std::map<int ,map<int, int>>::iterator it = ::mhash.find(k);

	if (it != mhash.end()) {
		m = it->second;
		return;
	}

	while(k != 1){

		push(m,least[k],1);
		k=k/least[k];
	}

	// while(k%2==0){
 // 		push(m,2,1);
 // 		k = k/2;
 // 	}

 // 	for (int i = 3; i < sqrt(k); i = i+2)
 // 	{
	// 	while(k%i==0){
	//  		push(m,i,1);
	//  		k = k/i;
	//  	} 		
 // 	}

 // 	if(k>2) push(m,k,1);

 	mhash.insert({k,m});

} 



int main(int argc, char const *argv[])
{
	int t;
	calcLeast();

	std::fstream myfile("./input.txt", std::ios_base::in);

	myfile>> t;

	// cout<<"t "<<t<<endl;

	
	while(t--){
		int n;
		map<int,int> factors;

		myfile >> n;

		// cout<<"n "<<n<<endl;
		
		while(n--){

			int a;
			map<int,int> current_facts;

			myfile >> a;
			// cout<<"a "<<a<<endl;
			getFactors(current_facts, a);

			// cout<<"current facts "<<endl;
			// printIt(current_facts);

			for (auto itr = current_facts.begin(); itr != current_facts.end(); ++itr) { 
		        push(factors , itr->first, itr->second);     
		 	} 

		}

		int total=1;


		// cout<<"factors "<<endl;
		// printIt(factors);

		for (auto itr = factors.begin(); itr != factors.end(); ++itr) { 
	        total = total*(itr->second+1);     
	 	}

	 	cout<<total<<endl; 
	}

	return 0;
}