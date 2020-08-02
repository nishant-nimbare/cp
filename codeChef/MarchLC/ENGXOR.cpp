#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <fstream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	std::fstream myfile("../input.txt", std::ios_base::in);

	myfile>> t;
	
	while(t--){
		int n,q;
		myfile >> n >> q;
        long long int temp=0;
        cout<<"n "<<n<<"\t q "<<q<<'\n';
        // vector<long long int> A;
        // vector<int> P;

        vector<int> mapping1[32];
        vector<int> mapping0[32];


		 for (int i = 0; i < n; i++) {
             myfile>>temp;
            //  A.push_back(temp);
            //  cout<<"Ai "<<temp<<'\n';

             for (int k = 0; k < 32; k++){
                if(temp & 1){
                    //k th bit set
                    mapping1[k].push_back(i);
                }else{
                    mapping0[k].push_back(i);
                } 

                temp = temp >> 1;
            }


		}


        for (int i = 0; i < q; i++){
            myfile>>temp;
            // P.push_back(temp);
            //  cout<<"Pi "<<temp<<'\n';

            unordered_map<int,int> count;

            for (int k = 0; k < 32; k++){
                
                if(temp & 1){
                    //k th bit set
                    for(auto itr : mapping0[k]) count[itr]+=1;
                }else{
                    for(auto itr : mapping1[k]) count[itr]+=1;
                } 

            temp = temp >> 1;
            }

            int odd = 0, even =0;
            for(auto c: count){
                
                if(c.second & 1){
                    //odd
                    odd++;
                }else{
                    //even
                    even++;
                }

            }

            cout<<even<<' '<<odd<<'\n';	

        }

    }

	return 0;
}