#include <bits/stdc++.h>

#ifdef DEBUG
#define dout cout
#else
#define dout 0 && cout
#endif

using namespace std;

void PrintMap(unordered_map<int,int> mmap, string name){
    cout<<name<<"\t";
    for(auto p : mmap){
        cout<<p.first<<"->"<<p.second<<" ";
    }
    cout<<"\n";
}

long long int two(vector<int> arr){
    unordered_map<int, int> imap, lmap;
    size_t n = arr.size();
    long long int ans=0;

    for(int j = 0; j<n; j++){

        // PrintMap( imap, " i-map");

        lmap.clear();

        for(int k=n-1; k>j; k--){

            // PrintMap(lmap, " L-map");
            
            // if(imap[arr[k]]*lmap[arr[j]]>0) cout<<" - - - 2.found "<<j<<" "<<k<<" "<<imap[arr[k]]*lmap[arr[j]]<<"\n";

            ans += imap[arr[k]]*lmap[arr[j]];

            lmap[arr[k]]++;
        }

        imap[arr[j]]++;
    }

    // cout << ans << "-- my \n";
    return ans;
}





void makeTest(){

    srand(time((NULL)));


    while (true) {
        // make test cases till ans is same

        int n = (rand() % 20) + 4;   // 2<= n <= 10^5
        vector<int> arr;
        cout<<n<<" - test  ";
        for (int i = 0; i < n; i++) {
            arr.push_back(rand() % 10);
            cout<<arr.back()<<" ";
        }
        cout<<"\n";

        if (one(arr) != two(arr)) {
            break;
        }
    }

}

void customTest(){
    vector<int> arr {3, 4, 5, 0, 2, 3, 1, 1, 6};
    two(arr);
}

int main(int argc, char const *argv[]){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // makeTest();
    // customTest();
    // return 0;

	int t;
	cin>> t;
	
	while(t--){
		int n;
		cin >> n;

        vector<int> arr(n);

		for (int i = 0; i < n; i++) {
			 cin>>arr[i];
		} 

        cout<<two(arr)<<"\n";
    
	}

	return 0;
}