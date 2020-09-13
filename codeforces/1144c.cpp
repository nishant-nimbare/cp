#include <bits/stdc++.h>

#define DEBUG true

#ifdef DEBUG
#define dout cout
#else
#define dout 0 && cout
#endif

using namespace std;


int main(int argc, char const *argv[]){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    map<int, int> mp;

    for (int i = 0; i < n; i++) {
        int a; cin>>a;
        mp[a]+=1;
    } 


    vector<int> a,b;

    bool flag=false;

    for (auto p : mp) {
        if(p.second > 2){
            flag = true;
            break;
        }

        a.push_back(p.first);

        if(p.second == 2) b.push_back(p.first);
    }


    if(flag){
        cout<<"NO\n";
    }else{
        cout<<"YES\n";
        
        std::reverse(b.begin(), b.end());

        cout<<a.size()<<endl;
        for(int x : a) cout<<x<<" ";
        cout<<endl;

        cout<<b.size()<<endl;
        for(int x : b) cout<<x<<" ";
        cout<<endl;

    }
	return 0;
}