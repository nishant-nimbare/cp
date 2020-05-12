#include <iostream>
#include <unordered_map>
#define lli long long int
using namespace std;
// 1_000_000_000_039
// 1_000_000_000_061
lli m1 = 1000000000039;
lli m2 = 1000000000061;
lli x =263;

lli mod(lli n, lli prime){
    return ((n%prime)+prime)%prime;
}

lli mpow(lli base, lli exp, lli prime){

    if( exp == 0 ) return 1;
    
    if( exp == 1 ) return mod(base, prime);

    if( exp&1 ){ //odd
        return mod( mod(base, prime) * mpow( mod(base*base, prime) , exp/2, prime ) , prime);
    }else{ //even
        return  mod( mpow( mod(base*base, prime) , exp/2, prime ) , prime );
    }

}

lli shash1[100001];
lli shash2[100001];

lli thash1[100001];
lli thash2[100001];

unordered_map<lli,size_t> seen;


struct Answer {
	size_t i, j, len;
};


bool check(size_t a,size_t b,size_t k){
	return false;
}


Answer solve(const string &s, const string &t) {
	// for (size_t i = 0; i < s.size(); i++)
	// 	for (size_t j = 0; j < t.size(); j++)
	// 		for (size_t len = 0; i + len <= s.size() && j + len <= t.size(); len++)
	// 			if (len > ans.len && s.substr(i, len) == t.substr(j, len))
	// 				ans = {i, j, len};
	
	
	
	// initialze hashes

	// cout<<"\n-------\n -s "<<s<<"  - t"<<t<<"\n";


	// cout<<" - computing shash\n";
	// for s 
	shash1[0]= mod( (int)s[0], m1);
	shash2[0]= mod( (int)s[0], m2);

	for(int i=1; i<s.length(); i++){
		shash1[i] = mod( mod( shash1[i-1]*x , m1) + s[i] , m1);
		shash2[i] = mod( mod( shash2[i-1]*x , m2) + s[i] , m2);
	}

	// cout<<" - computing thash\n";
	// for t
	thash1[0]= mod( (int)t[0], m1);
	thash2[0]= mod( (int)t[0], m2);

	for(int i=1; i<t.length(); i++){
		thash1[i] = mod( mod( thash1[i-1]*x , m1) + t[i] , m1);
		thash2[i] = mod( mod( thash2[i-1]*x , m2) + t[i] , m2);
	}


	size_t l=0,r=min(s.length(), t.length()), mid;
	size_t curA=0,curB=0;


	while(l<=r){
		bool found = false;
		mid = (r-l)/2 + l;

		// cout<<" - trying for length "<<mid<<"\n";

		seen.clear();
		seen.insert({shash1[mid-1], 0});

		for(int i=1; i<=s.length()-mid; i++){
			seen.insert({ mod(shash1[i+mid-1] - mod(mpow(x,mid,m1)*shash1[i-1], m1), m1) , i });
		}

		// cout<<" - inserted all shash1 s in seen size : "<< seen.size() <<"\n";

		lli ch = thash1[mid-1];
		if(seen.find(ch) != seen.end()){
			//compare 2nd hash
			if(shash2[mid-1] == thash2[mid-1]){
				// found sub string
				curA = seen.find(ch)->second;
				curB = 0;
				found = true;
			}
		}

		for(int i=1; i<=t.length()-mid; i++){

			unordered_map<lli,size_t>::iterator itr = seen.find(
				mod(thash1[i+mid-1] - mod(mpow(x, mid, m1)*thash1[i-1], m1) , m1)
			);

			if( itr != seen.end()){
				//compare 2nd hash
				lli sh2 = mod( shash2 [(itr->second)+mid-1] - mod(mpow(x,mid,m2)*shash2[(itr->second)-1], m2), m2);
				lli th2 = mod( thash2 [i+mid-1] - mod(mpow(x,mid,m2)*thash2[i-1], m2), m2);

				if(sh2 == th2){
					// found sub string
					curA = itr->second;
					curB = i;

					// move binary search to right
					found = true;
					break;
				}
			}

		}
		

		if(found) {
			l= mid+1;
			// cout<<" - - found "<<curA<<"  "<<curB<<"\n";
		}else{
			r=mid-1;
		}

	}


	size_t comSubLen = l-1;

	Answer ans = {curA, curB, comSubLen};
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	string s, t;
	while (cin >> s >> t) {
		// cout<<s<<"\t"<<t<<"\n";
		auto ans = solve(s, t);
		cout << ans.i << " " << ans.j << " " << ans.len << "\n";
	}
}
