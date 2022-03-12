#include <bits/stdc++.h>

// #define DEBUG true

#ifdef DEBUG
#define dout cout
#else
#define dout 0 && cout
#endif

#define PS << " - " <<
#define PG << "  " <<
#define PE << endl

using namespace std;

void printVec(string name, vector<int> a) {
    dout << name << " : ";
    for (auto x : a) dout << x << " ";
    dout << endl;
}

struct ant{
    int val;
    bool dir;
    ant(int x) : val(x) {
        dir = (x<0);
    }
};

bool comp(const ant &lhs, const ant &rhs){
    return (lhs.val<=rhs.val);
}


int main(int argc, char const *argv[]) {


    int t;
    cin >> t;

    while (t--) {

        int n; cin >> n;

        vector<vector<ant>> lines;

        for (int i = 0; i < n; i++) {
            
            int m,x; cin>>m;
            vector<ant> arr;

            for(int i=0; i<m; i++) {
                cin>>x;
                arr.push_back(ant(x));
            }

            sort(arr.begin(), arr.end(), &comp);
            lines.push_back(arr);
        }

        // dout<<lines.size()<<endl;
        // for(auto v:lines) {
        //     for(auto x: v) dout<<x.val<<" ";
        //     dout<<endl;
        // }
        int  ans=0;

        for(auto ln : lines){

            int l=0, r=ln.size()-1;

            int cur = 0;
            while(l<=r){

                dout PS ln[l].val PG ln[r].val PG cur PG ans PE;

                if(l == r){
                    cur += (cur&1) ? (1):(0);
                    
                    dout PS "adding" PG cur PE; 
                    ans += cur;

                    break;
                }

                if(ln[l].dir && !ln[r].dir){

                    cur += (cur&1) ? (2):(1);
                 
                    dout PS "adding" PG cur PE; 
                    ans += 2*cur;
                }

                if((ln[l].dir && ln[r].dir) || (!ln[l].dir && !ln[r].dir)){

                    cur += (cur&1) ? (1):(0);

                    dout PS "adding" PG cur PE; 
                    ans += 2*cur;
                }

                l++;
                r--;
            }        
        }

        cout<<ans/2<<endl;
    }

    return 0;
}


/****
 * 1,0 = 0
 * 2,0 = 0
 * 1,1 = 1
 * 2,1=  2
 * 2,2 = 4
 * 3,1 = 3
 * 3,2 = 6
 * 3,3 = 9
 * *****/