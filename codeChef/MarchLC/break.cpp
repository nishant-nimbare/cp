#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <fstream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

std::fstream myfile("../input.txt", std::ios_base::in);

bool task1(){
        int n;
		myfile >> n;

        int a[n],b[n];
        unordered_map<int,int> mmap;

        for (int i = 0; i < n; i++) {myfile>>a[i]; mmap[a[i]]+=1; }
        for (int i = 0; i < n; i++) {myfile>>b[i]; mmap[b[i]]+=1; }

        sort(a,a+n);
        sort(b,b+n);

        int flag =0;

        // cout<<"map\n";
        // for(auto itr : mmap){
        //     cout<<itr.first<<"->"<<itr.second<<"\n";
        // }
        // cout<<"\n";

        unordered_set<int> table;

        for (int i = 0; i < n; i++) {

            if( (table.find(a[i]) == table.end()) && i!=0 ){
                return false;
            }


            if(b[i]<=a[i]){
                // cout<<"NO\n";
                return false;
            }

            table.insert(a[i]);
            table.insert(b[i]);

            // if(mmap[a[i]]==1){
            //     if(flag == 0 ) {
            //         //first occurence
            //         flag=1;
            //     }else if(flag == 1){
            //         //2 numbers with only 1 occurence
            //         // cout<<"NO\n";
            //         return false;    
            //     }
            // }

            

        }


        // cout<<"YES\n";
        return true;
}

bool task2(){
        int n;
		myfile >> n;

        int a[n],b[n];
        // unordered_map<int,int> mmap;

        for (int i = 0; i < n; i++) {myfile>>a[i]; }
        for (int i = 0; i < n; i++) {myfile>>b[i]; }

        sort(a,a+n);
        sort(b,b+n);

        // bool player=false;

        // for (int i = 0; i < n; i++) {
        //     player = !player;
        //     int A,B;
        //     if(player){
        //         //chef playing
        //         A=a[i];
        //         B=b[i];
        //     }else{
        //         A=b[i];
        //         B=a[i];
        //     }

        //     if(B<=A){
        //         // cout<<"NO\n";
        //         return false;
        //     }
        // }
        // cout<<"YES\n";
        if(a[0]>=b[0]) return false;

        return true;
}


int main(int argc, char const *argv[]){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int t,s;


	myfile>>t>>s;
	
	while(t--){
		bool ans;
        if(s==1) ans = task1();
        else ans = task2();
    
        if(ans) cout<<"YES\n";
        else cout<<"NO\n";
    
    }

	return 0;
}