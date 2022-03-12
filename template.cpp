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

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

void printVec(string name,vector<int> a){ dout<<name<<" : "; for(auto x:a) dout<<x<<" "; dout<<endl;}

// printBT for printing tree horizontally


int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    //cout<< std::fixed << std::setprecision(3)<<ans;
    // std::fstream myfile("./input.txt", std::ios_base::in);

    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n);

        for(int &x : arr) cin>>x;

    }

    return 0;
}
