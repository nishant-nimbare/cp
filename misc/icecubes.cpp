#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	int n,t;
	cin>>n;
    bool allsame=false;
    vector<int> arr;

    int totalSets = 0;
    for (int i = 0; i < n; i++)
    {
        cin>>t;
        arr.push_back(t);
    }
    
    sort(arr.begin(),arr.end(),greater<int>());

    // cout<<"sorted "<<endl;

    // for(auto it=arr.begin(); it!=arr.end() ; ++it){
    //     cout<<" "<<*it;
    // }
    // cout<<endl;

	while((arr.size()!=0)){
		
        int size=0;
        int prev=-1;
        for(auto it=arr.begin(); it!=arr.end() ; ++it){
            
            if((prev!=-1 && prev>*it) || prev==-1){
                size++;
                prev=*it;
                arr.erase(it);
                --it; 
                // allsame=false;
            }
            

            // if(prev!=-1 && prev==*it){
            //     allsame=true;
            // }

            if(size == 3){
                totalSets++;
                break;
            }

        }
	}


    cout<<totalSets<<endl;
	return 0;
}


// #include <cmath>
// #include <cstdio>
// #include <vector>
// #include <iostream>
// #include <algorithm>
// using namespace std;


// int main() {
//     int n,t;
//     cin>>n;
//     bool allsame=false;
//     vector<int> arr;

//     int totalSets = 0;
//     for (int i = 0; i < n; i++)
//     {
//         cin>>t;
//         arr.push_back(t);
//     }
    
//     sort(arr.begin(),arr.end(),greater<int>());

//     // cout<<"sorted "<<endl;

//     // for(auto it=arr.begin(); it!=arr.end() ; ++it){
//     //     cout<<" "<<*it;
//     // }
//     // cout<<endl;

//     while((arr.size()!=0)){
        
//         int size=0;
//         int prev=-1;
//         for(auto it=arr.begin(); it!=arr.end() ; ++it){
            
//             if((prev!=-1 && prev>*it) || prev==-1){
//                 size++;
//                 prev=*it;
//                 arr.erase(it);
//                 --it; 
//                 // allsame=false;
//             }
            

//             // if(prev!=-1 && prev==*it){
//             //     allsame=true;
//             // }

//             if(size == 3){
//                 totalSets++;
//                 break;
//             }

//         }
//     }


//     cout<<totalSets<<endl;
//     return 0;
// }
