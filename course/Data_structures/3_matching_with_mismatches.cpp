#include <iostream>
#include <vector>
#define lli long long int
using namespace std;

bool logs=false;

template <typename T>
void mlog(string txt, T val){
	if(logs) cout<<txt<<" "<<val<<"\t";
}

lli m1 = 1000000007;
lli m2 = 1000000009;
lli x =263;

lli mod(lli n, lli prime){
    lli ans = (n%prime);
	if(ans<0) ans+=prime;
	
	return ans;
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

lli phash1[100001];
lli phash2[100001];

lli thash1[200001];
lli thash2[200001];

bool match(size_t tl, size_t pl,size_t len){

	cout<<"match called "<<tl<<" "<<pl<<" "<<len<<"\n";

	if(len==0) return false;

	lli th1, ph1;

	if(tl==0) th1 = thash1[tl+len-1];
	else th1 = mod( thash1[tl+len-1]- mod(mpow(x, len, m1)*thash1[tl-1], m1), m1);
	

	if(pl==0) ph1 = phash1[pl+len-1];
	else ph1 = mod( phash1[pl+len-1]- mod(mpow(x, len, m1)*phash1[pl-1], m1), m1); 
	

	//check 1st hash
	// cout<<th1<<" :th1 "<<ph1<<" :ph1 \n";
	if(th1 == ph1){

		lli th2, ph2;

		if(tl==0) th2 = thash2[tl+len-1];
		else th2 = mod( thash2[tl+len-1]- mod(mpow(x, len, m2)*thash2[tl-1], m2), m2);
		

		if(pl==0) ph2 = phash2[pl+len-1];
		else ph2 = mod( phash2[pl+len-1]- mod(mpow(x, len, m2)*phash2[pl-1], m2), m2); 		

		// cout<<th2<<" :th2 "<<ph2<<" :ph2 \n";
		if(th2==ph2) return true;

	}

	return false;
}

size_t findNextMis( size_t tl, size_t pl,size_t len ){

	size_t tr=tl+len-1, mid; //right inclusive
	

	if( match(tl,pl,len) ){ // whole strings are same
		return tl+len;
	}

	if(len == 1){ // there is one char and it didn't match in above if
		return tl;
	}

	//binary search for k
	while(len>1){
		mid = (tr-tl)/2 + tl;

		mlog<int>(" - tl",tl);
		mlog<int>(" - pl",pl);
		mlog<int>(" - len",len);

		bool flag =match(tl, pl, len/2); 
		mlog<bool>(" - flag ",flag);
		
		// mlog<char>("\n",'\n');
		
		if( flag ){
			//left half matches, mismatch in right half
			
			/* len is 2 and it is a match for left half i.e 1st char
				this means that there is a mismatch at 2nd char (right half)
			*/ 
			// cout<<" f true \n";

			if(len==2){
				return tl+1;

			}

			if(len == 3){
				len=2;
				tl+=1;
				pl+=1;
				continue;
			}


			tl+=(len/2);
			pl+=(len/2);

			

		}else{
			//mismatch found in left half , search in left half
			// cout<<" f false \n";
			
			if(len == 2 || len==3){
				return tl;
			}
		}

		len -= (len/2);

	}

	return 0;
}


vector<int> solve(int k, const string &text, const string &pattern) {
	vector<int> pos;
	
	size_t tlen = text.length();
	size_t plen = pattern.length();

	// cout<<" tlen plen "<<tlen<<" "<<plen<<"\n";
	mlog<size_t>("tlen",tlen);
	mlog<size_t>("plen",plen);

	

	thash1[0] = mod( (text[0]-'a'), m1);
	thash2[0] = mod( (text[0]-'a'), m2);

	// cout<<" thash10 "<<thash1[0];
	// cout<<" thash20 "<<thash2[0];


	for(int i=1; i<tlen; i++){
		thash1[i] = mod( mod( thash1[i-1]*x , m1) + (text[i]-'a') , m1);
		thash2[i] = mod( mod( thash2[i-1]*x , m2) + (text[i]-'a') , m2);
	}


	phash1[0] = mod( ( pattern[0]-'a'),m1);
	phash2[0] = mod( ( pattern[0]-'a'),m2);


	// cout<<" phash10 "<<phash1[0];
	// cout<<" phash20 "<<phash2[0]<<"\n";


	for(int i=1; i<plen; i++){
		phash1[i] = mod( mod( phash1[i-1]*x , m1) + (pattern[i]-'a') , m1);
		phash2[i] = mod( mod( phash2[i-1]*x , m2) + (pattern[i]-'a') , m2);
	}


	mlog<char>("hashing done\n", ' ');

	// from every pos in text , check for next k mismatches
	for(int i=0;i<=tlen-plen; i++){

		mlog<int>("\n-----",i);
		mlog<char>("\n",'\n');


		int totalMiss =0;
		size_t tl=i, pl=0, remSize=plen;

		while(totalMiss<=k){
			
			mlog<int>("totalMiss",totalMiss);
			mlog<int>("tl",tl);
			mlog<int>("pl",pl);
			mlog<int>("remsize",remSize);

			size_t curmiss = findNextMis(tl,pl,remSize);

			mlog<int>("curMiss", curmiss);
			mlog<char>("\n",'\n');

			if( curmiss >= i+plen ){
				//matched
				pos.push_back(i);
				break;
			}

			int dff =curmiss-tl;
			tl+= dff+1;
			pl+= dff+1;
			remSize = plen-pl;
			
			if(remSize==0 && totalMiss<k){
				// got a miss on the last character
				pos.push_back(i);
				break;
			}

			totalMiss++;
		}
	} 

	
	return pos;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int k;
	string t, p;
	while (
		cin >> k >> t >> p
		) {
		// cout<<k<<(lli)t[0]<<" "<<(lli)p[0]<<"\n";
		auto a = solve(k, t, p);
		cout << a.size();
		for (int x : a)
			cout << " " << x;
		cout << "\n";
	}
}
