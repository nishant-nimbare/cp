#include <bits/stdc++.h>

#define DEBUG true

#ifdef DEBUG
#define dout cout
#else
#define dout 0 && cout
#endif

#define PS <<" - "<<
#define PG <<"  "<<
#define PE <<endl

using namespace std;

void printVec(vector<int> a){ for(auto x:a) dout<<x<<" "; dout<<endl;}

int main(int argc, char const *argv[]) {

    int t;
    cin >> t;

    //cout<< std::fixed << std::setprecision(3)<<ans;
    // std::fstream myfile("./input.txt", std::ios_base::in);

    while (t--) {
        int n,m;
        cin>>n>>m;

        vector<int> a(n), b(m);

        int at=0, bt=0;
        for(int &x : a){ cin>>x; at+=x;}
        for(int &x : b){ cin>>x; bt+=x;}
        
        if(at > bt){ cout<<"0";  if(t>0) cout<<endl; continue;}
        
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
 
        //printVec(a);
        //printVec(b);

        int diff = bt-at;
        int i=0, mmax = min(n,m)-1;
        dout<<" diff : "<<diff<<"  "<<mmax<<endl;

        while((diff>=0) && (i<=mmax)){
            //swap a[i] and b[m-1-i]
            int sdiff = (b[m-1-i] - a[i]);
            
            if( sdiff < 0) break;
           
            diff -=2* sdiff;
            i+=1;
            dout<<"swapping "<< b[m-1-i] <<" "<< a[i]<< " == "<<diff<<endl;
        
            //std::swap(b[m-1-i], a[i]);
        }

        dout<<" after swapping :"<<endl;
        
        printVec(a);
        printVec(b);
        
        if( diff >= 0 ) cout<<"-1";
        else cout<<i;
        
        if(t>0) cout<<endl;
    }

    return 0;
}

