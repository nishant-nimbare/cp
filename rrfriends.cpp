#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

const int MAX = 2000;

int main(int argc, char const *argv[])
{
	int n;
	std::fstream ip("./input.txt", std::ios_base::in);

	ip>> n;
	
    vector< bitset<MAX> > arr;
    vector< bitset<MAX> > dp;

    bitset<MAX> zero(0);

	for(int i=0;i<n;i++){

        string s;
        ip>>s; // Suppose s = "100100101"
        // int a = stoi(s, 0, 2);

        reverse(s.begin(),s.end());
        bitset<MAX> a(s);
        // cout<<a; // 293

        a[i]=0;
        arr.push_back(a);
        dp.push_back(zero);
    
    }

    long long int ans =0;

	for(int i=0;i<n;i++){
        bitset<MAX> current = arr[i];
        // cout<<"current "<<current<<"\n\t";

    	for(int j=0;j<n;j++){

            if(!current[j]){

                // cout<<i<<" and "<<j<<" are not friends\n";
                continue;
            }

            bitset<MAX> temp=arr[j];
            // cout<<"temp "<<temp<<"\n\t";
            
            temp = current & temp.flip();
            // cout<<"count "<<temp.count()<<"\n\t";

            temp[i]=0;
            temp[j]=0;

            dp[j] = dp[j] | temp;

            // if(temp.count()>1)
            //     ans=ans+temp.count();

            // cout<<"ans "<<ans<<"\n\t";

        }    
        // cout<<"-------------------\n";

    }    

    cout<<"-------------------\n";


	for(int i=0;i<n;i++){
        ans+=dp[i].count();
        // cout<<dp[i]<<"\n";
    }
    cout<<"-------------------\n";



    cout<<"finale ans  "<<ans<<"\n";

	return 0;
}

