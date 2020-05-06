#include <bits/stdc++.h>
using namespace std;

const int hsize = 100000;

//storing lower triangular matrix in arr.
bool mhash[hsize];


bool mgcd(int a,int b, bool first){

	// cout<<" * * gcd call for "<<a<<' '<<b<<'\n';
	if( b==0){
		// a is the gcd
		if(a==1)return true;
		return false;
	}

	int index = ((a*(a-1))/2) + b;

	if( (index < hsize) && (!first) ){
		return mhash[index];
	}


	bool ans = mgcd(b, a%b, false);
	if((index < hsize) && first){
		// cout<<" - gcd "<<a<<' '<<b<<" = "<<ans<<'\n';
		mhash[index] = ans;
	}
	return ans;
}


// bruteforcing

int main(int argc, char const *argv[]) {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    // std::fstream myfile("./input.txt", std::ios_base::in);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        unordered_map<int, vector<int> > days;

        for (int p = 1; p <= n; p++) {
            // cout << " trying for " << p << '\n';
            bool f = false;
            int d = 0;
            while (d < days.size()) {
				f=false;
                for (int k = 0; k < days[d].size(); k++) {
                    
                    // if (__gcd(days[d][k], p) != 1) {
                    if (!mgcd(p,days[d][k],true)) {
                    	// cout << " * * clashing with page " << days[d][k] << '\n';
						d += 1;
                        f = true;
                        break;
                    }
                }

                // p is coprime with each of pages of days[d];
                if (!f) {
                    // cout << " - inserting in day " << d << '\n';
                    days[d].push_back(p);
                    break;
                }
            }

            if (d >= days.size()) {
                // clashing with all previous days
				// cout << " + making a new day " << d << '\n';
				vector<int> new_vec{p};
                days.insert({d, new_vec});
            }
        }

        // Printing answers
        cout << days.size() << '\n';
        for (auto day : days) {
            // CHANGE THIS LATER
            cout<<day.second.size()<<' ';
            // cout << day.first << ' ';

            for (auto p : day.second) {
                cout << p << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}