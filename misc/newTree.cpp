#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <fstream>
#include <set>
using namespace std;


int main(int argc, char const *argv[])
{
    int t;
    // std::fstream myfile("./input.txt", std::ios_base::in);

    cin>> t;
    
    while(t--){
        int n,temp=0;
        cin >> n;

        int neededShopes=0;

        vector<int> shops;
        shops.push_back(0); //i based indexing
        for (int i = 0; i < n; i++)
        {
            cin>>temp;
            // cout<<"temp "<<temp<<endl;
            shops.push_back(temp);
        }


        // cout<<"shops"<<endl;
        // for(auto ite=shops.begin();ite!=shops.end();++ite) cout<<*ite; 
        // cout<<endl;

        n-=1;
        
        set<int> leaves;
        set<int> parents;

        while(n--){
            int a,b;
            cin>>a>>b;

            set<int>::iterator aItp = parents.find(a);
            set<int>::iterator bItp = parents.find(b);

            
            set<int>::iterator aIt = leaves.find(a);
            set<int>::iterator bIt = leaves.find(b);

            if((aItp == parents.end()) && (aIt == leaves.end())){
                //new a
                leaves.insert(a);
                
            }
            
            if((aItp == parents.end()) && (aIt != leaves.end())){
                // a 2nd occurance
                leaves.erase(aIt);
                parents.insert(a);
            }
            
            
            if((bItp == parents.end()) && (bIt == leaves.end())){
                //new b
                leaves.insert(b);
                
            }
            
            
            if((bItp == parents.end()) && (bIt != leaves.end())){
                // b 2nd occurance
                leaves.erase(bIt);
                parents.insert(b);
            }
            

//             if()
            
//             if((aIt == leaves.end()) && (bIt == leaves.end())){

//                 //both a and b are not in leaves add them
//                 leaves.insert(b);
//                 continue;
//             }

//             if( aIt != leaves.end() ){
//                 // a is already persent, a is a parent;
//                 leaves.erase(aIt);
//                 parents.insert(a);
//                 leaves.insert(b);
//                 continue;
//             }


//             if( bIt != leaves.end() ){
//                 // b is already persent, b is a parent;
//                 leaves.erase(bIt);
//                 parents.insert(b);
//                 leaves.insert(a);
//                 continue;
//             }



        } 

        // cout<<"leaves"<<endl;
        // for(auto ite=leaves.begin();ite!=leaves.end();++ite) cout<<*ite; 
        // cout<<endl;


        // cout<<"parents"<<endl;
        // for(auto ite=parents.begin();ite!=parents.end();++ite) cout<<*ite; 
        // cout<<endl;

        for(auto ite=parents.begin();ite!=parents.end();++ite){
            
            if(shops[*ite] != 1){
                //parent doesnt have a shop
                neededShopes++;
            }
        }

        cout<<neededShopes<<endl;
    }

    return 0;
}