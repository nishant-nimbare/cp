#include <bits/stdc++.h>
# define MOD 1000000007
using namespace std;


// 2
// 3
// 6 6 6
// 3
// 0 1 0

void printMap(map <int,int, greater<int> > mmap){

	cout<<" map ...\n";
	for(auto i:mmap) cout<<i.first<<" -> "<<i.second<<'\n';
	cout<<'\n';
}

int main(int argc, char const *argv[])
{

	// ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

	int t;
	// std::fstream myfile("./input.txt", std::ios_base::in);

	cin>> t;
	
	while(t--){
		int n;
		cin >> n;

		int ymax=INT_MIN;
		map<int,int, greater<int> > cars;

		// cout<<"starting..\n";

		int temp;
		for (int i = 0; i < n; i++) {
			cin>>temp;
			// cout<<temp<<" input\n";
			ymax = max(ymax,temp);
			cars[temp]+=1;
		} 
		// printMap(cars);
		// cout<<" ymax "<<ymax;



		long long int profit=0;
		for(int y=0; ( y<ymax && cars.size()>0 ) ; y++){
			cars.erase(y);
			// cout<<" - current year"<<y<<'\t';
			// printMap(cars);

			if( cars.size() == 0 ) break;
			auto itr  = cars.begin();
			
			// cout<< " - car selected "<<itr->first<<'\n';
			if(itr->second > 0) {
			    profit += (itr->first - y)%MOD ;
                profit = profit%MOD;
			}
			
			itr->second = itr->second - 1;
			
			if(itr->second <=0 ) cars.erase(itr);
			if( cars.size() == 0 ) break;
			// cout<<" profit "<<profit<<"\n*\n*\n";
		}

		cout<<(profit%MOD)<<'\n';

		// cout<<"----------------------****************-----------------\n";
	}

	return 0;
}