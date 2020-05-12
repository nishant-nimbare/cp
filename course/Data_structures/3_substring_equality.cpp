#include <iostream>
#define lli long long int
using namespace std;

lli m1 = 1000000007;
lli m2 = 1000000009;
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

lli hash1[500001];
lli hash2[500001];


class Solver {
	string s;
public:	
	Solver(string s) : s(s) {	
		// initialization, precalculation
	
	
		hash1[0]= mod( (int)s[0], m1);
		hash2[0]= mod( (int)s[0], m2);

		for(int i=1; i<s.length(); i++){

			hash1[i] = mod( mod(hash1[i-1]*x , m1) + s[i] , m1);
			hash2[i] = mod( mod(hash2[i-1]*x , m2) + s[i] , m2);
		}

	
	
	}
	bool ask(int a, int b, int l) {
		lli ah1 = mod(hash1[a+l-1] - mod( mpow(x, l, m1 )*hash1[a-1], m1 ), m1);
		lli bh1 = mod(hash1[b+l-1] - mod( mpow(x, l, m1 )*hash1[b-1], m1 ), m1);
		// cout<<" - "<<ah1<<"	"<<bh1<<"\n";  
		if( ah1 == bh1 ){
			
			lli ah2= mod(hash2[a+l-1] - mod( mpow(x, l, m2 )*hash2[a-1], m2 ), m2),
			bh2= mod(hash2[b+l-1] - mod( mpow(x, l, m2 )*hash2[b-1], m2 ), m2);

			// cout<<" - - "<<ah2<<"	"<<bh2<<"\n";  

			if( ah2 == bh2) return true;	
		}

		return false;
	}
};

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	string s;
	int q;
	cin >> s >> q;
	Solver solver(s);
	for (int i = 0; i < q; i++) {
		int a, b, l;
		cin >> a >> b >> l;
		cout << (solver.ask(a, b, l) ? "Yes\n" : "No\n");
	}
}
