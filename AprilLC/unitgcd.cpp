#include <bits/stdc++.h>

using namespace std;

// 1
// 10

const int M = 1000001;
bitset<M> read;
bitset<M> current;

void printVec(vector<int> vec){
	for(auto i:vec) cout<<i<<' ';
	cout<<'\n';
}

int main(int argc, char const *argv[]){

	// ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

	int t;

	cin>> t;
	
	while(t--){
		int n;
		cin >> n;
		// cout<<"n "<<n<<'\n';
		vector< vector<int> > days;
		// int its=0;
		while( read.count() < n ){
			// cout<<" read count "<<read.count()<<'\n';

			vector<int> pages;
			current.set(); //set all bits

			for(int i=1; i<=n; i++){

				// cout<<" - i = "<<i<<" read = "<<read[i]<<" current = "<<current[i]<<'\n';
				// cout<<" - "<<read<<'\n';
				// cout<<" - "<<current<<'\n';

				if( read[i] == 0 ){ //page not already read
					
					if( current[i] == 1 ){ //not clashing with other pages
						// cout<<" - - reading "<<i<<'\n';
						read[i] = 1;
						pages.push_back(i);

						if(read.count()==n) break;

						if( i>1 ) {
							// cout<<" - - - starting loop for "<<i<<'\n';
							for(int j=i; j<=n; j=j+i){
							 current[j] = 0;
							//  cout<<" - - - chaning current "<<current<<'\n';
							 }
						}
					} 
				}
			}
			// cout<<" pages  ";
			// printVec(pages);
			days.push_back(pages);
			// its++;
		}

		cout<<days.size()<<'\n';
		for(auto d : days){
			cout<<d.size()<<" ";
			for( auto i: d){
				cout<<i<<' ';
			}
			cout<<'\n';
		}

	}

	return 0;
}