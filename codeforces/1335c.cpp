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
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin >> n;

        unordered_map<int, int> mp;

        int maxEle=-1, maxVal=-1;

        for (int i = 0; i < n; i++) {
            int a; cin>>a;
            mp[a]+=1;

            if(mp[a]>maxVal){
                maxEle = a;
                maxVal = mp[a];
            }
        } 

        int uniq=0;
        for(auto p : mp){

            if(p.first != maxEle) uniq++;

        }

        cout<<max(min(uniq, maxVal), min(uniq+1, maxVal-1))<<endl;
    }
	return 0;
}