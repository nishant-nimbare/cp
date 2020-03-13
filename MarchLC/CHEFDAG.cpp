#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <fstream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

unordered_map< int, unordered_set<int> > mmap;


void printMap(){
    cout<<'\n';
    for(int i=1;i <= mmap.size();i++){
        unordered_set<int> curSet = mmap[i];
        cout<<i<<" -> ";
        for(auto itr:curSet){
            cout<<itr<<" ";
        }
        cout<<"\n";
    }
}

void initializeMap(vector<int> permut){

    int size=permut.size();
    for(int i=0;i<size-1;i++){

        unordered_set<int> newSet;

        for(int j=i+1;j<size;j++){
                newSet.insert(permut[j]);
        }

        mmap.insert({ permut[i], newSet});
    } 
}


void updateMap(vector<int> permut){

    int size=permut.size();
    for(int i=1;i<size;i++){
        for(int j=0;j<i;j++){

            if( mmap.find(permut[i]) != mmap.end() ){
                mmap[permut[i]].erase(permut[j]);

                if( mmap[permut[i]].size() == 0 ) mmap.erase(permut[i]);
            }
        }
    }

    mmap.erase(permut[size-1]); 
}



int main(int argc, char const *argv[]){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int t;
	std::fstream myfile("../input.txt", std::ios_base::in);

	myfile>> t;
	
	while(t--){
		int n,k,temp;
		myfile >> n>>k;

        mmap.clear();


        vector<int> currentPer;
        for (int i = 0; i < k; i++) {

            //k permutations
            currentPer.clear();

            for (int j = 0; j < n; j++){
                myfile>>temp;
                currentPer.push_back(temp);
            }   

            if(i==0) initializeMap(currentPer);
            else{
                updateMap(currentPer);
            }

            // printMap();
        }


        //create 1 - 1 mapping  
        int mapping[n+1]={0};
        int indeg=0;
        for(int i=0; i < currentPer.size(); i++ ){
            int item = currentPer[i];

            for(auto s : mmap){

                if(s.second.find(item) != s.second.end()){
                    // item found
                    mapping[s.first] = item;
                    mmap.erase(s.first);
                    indeg+=1;
                    break;
                }
 
            }
 
        }



        cout<<(n-indeg)<<"\n";

        for(int i=1; i <=n; i++ ){
            cout<<mapping[i]<<' ';
        }
        cout<<'\n';
	}



	return 0;
}