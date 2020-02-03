#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <fstream>
using namespace std;

// input
// 1
// 3
// 1 3
// 2 5
// 6 9

std::vector <pair<int,int>> areas;


int isBetween(int a,int b,int l,int h){

    //fully in between
    if(a<=l && b>=h) return 1; // don't increase bombs

    if(l<=a && h>=b) return 2; // don't increase bombs , change area

    if(l<=a && (a<=h && h<=b) ) return 3; // don't increase bombs, update low

    if((a<=l && l<=b) && b<=h) return 4; // don't increase bombs, update high

    return 0; // increase bomb add new area (a,b)
}

void solve(int a,int b){

    cout<<"solving.. "<<a<<" "<<b<<endl;

    bool f = false;
    for (int i=0;i<areas.size();i++){
        
        int ans = isBetween(a,b,areas[i].first,areas[i].second);
        cout<<" |-- case "<<ans<<endl;        

        switch (ans){
            case 1:
                f=true;
                break;

            case 2:
                areas[i].first = a;
                areas[i].second = b;
                f=true;
                break;

            case 3:
                areas[i].first = a;                
                f=true;
                break;
            
            case 4:
                areas[i].second = b;                
                f=true;
                break;
            
            default:
                break;
        }

        if(f) break;
    }

    if(!f){
        // no intersections 
        cout<<"making area "<<a<<" "<<b<<endl;
        areas.push_back(make_pair(a,b));
    }

}

bool sortBySecond(const pair<int,int> &a,const pair<int,int> &b){

    return (a.second < b.second);

}


int main(int argc, char const *argv[])
{
	int t;
	std::fstream myfile("./input.txt", std::ios_base::in);



	myfile>> t;
	
	while(t--){
    
    std::vector <pair<int,int>> input;

        areas.clear();
		int n;
		myfile >> n;

		while(n--){

			int a,b;

            myfile>>a>>b;
            // input.push_back(make_pair(a,b));
            solve( a, b);
        
        }


        sort(input.begin(),input.end(), sortBySecond);

        for(int i=0;i<input.size();i++){
            // cout<<"solving.. "<<a<<" "<<b<<endl;
            solve( input[i].first, input[i].second );
		
        }

        cout<<areas.size()<<endl; 
        input.clear();
	}

	return 0;
}