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

#define F first
#define S second

#define MAXN 1024
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

void printVec(string name,vector<int> a){ dout<<name<<" : "; for(auto x:a) dout<<x<<" "; dout<<endl;}

// printBT for printing tree horizontally

bool mmap[MAXN+1]={};


void calc_or(int x, int k){

    if(k<0) {
        mmap[x] = true;
        return;
    }
    
    //kth bit is zero
    
    if(!(x & (1<<k))){
        
        calc_or( (x|(1<<k)), k-1);
    }

    calc_or(x, k-1);

}


void calc_and(int x, int k){
    if(k<0) {
        mmap[x] = true;
        return;
    }


    //kth bit is one
    
    if(x & (1<<k)){

        calc_and( x & (!(1<<k)) , k-1);
    
    }

    calc_and(x, k-1);
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    //cout<< std::fixed << std::setprecision(3)<<ans;
    // std::fstream myfile("./input.txt", std::ios_base::in);

    while (t--) {
        int n,m;
        cin>>n>>m;

        memset(mmap, false, sizeof(mmap));

        vi a(n);
        for(int &x : a) cin>>x;

        vi b(m);
        for(int &x : b) cin>>x;


        int mmax = *max_element(a.begin(), a.end());

        int max_bit = 32-(__builtin_clz(mmax));
        // int max_mask = 
        
        // OR
        for(int x : a){
            calc_or(x, max_bit-1);
        }

        dout<<"or done"<<endl;

        // AND
        for(int x : a){
            calc_and(x, max_bit-1);
        }

        dout<<"and done"<<endl;

        mmap[0] = true;
        ll ans=0;
        for(int i=0; i<=MAXN; i++){
            if(mmap[i]){
                dout<<i<<" ";
                ans++;
            }
        }
        dout<<endl;

        cout<<ans<<endl;
        dout<<" -------------- "<<endl;
    }

    return 0;
}
