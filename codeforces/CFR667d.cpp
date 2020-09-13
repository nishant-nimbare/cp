#include <bits/stdc++.h>

#define DEBUG true

#ifdef DEBUG
#define dout cout
#else
#define dout 0 && cout
#endif

#define lli long long int

using namespace std;

pair<int,int> getSum ( lli n){

    int sum = 0;

    bool flag = false;
    int idx = -1, i=0;

    while(n>0){
    
        int d = n%10;
        sum += d;
        n = n/10;

        if(d!=0 && !flag){
            idx = i;
            flag = true; 
        }

        i++;
    }

    return make_pair(sum, idx);
}


int to_int(char c){
    return (c-'0');
}

int main(int argc, char const *argv[]){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int t;
	cin>> t;
	
	while(t--){
		lli n;
        int s;
		cin>>n>>s;

        dout<<" - "<<n<<" "<<s<<endl;//" "<<sum<<endl;

        string num = to_string(n);
        size_t nlen = num.size();

        int sum =0;
        for (int i = 0; i < nlen; i++) {
            sum += to_int(num[i]); 
		} 


        if(sum<= s) {
            cout<<0<<endl;
            continue;
        }

        int ans =0;

        for(int i =nlen -1; i>=0; i-- ){
            if(to_int(num[i])!=0){
                ans += (10-to_int(num[i])) * (nlen-i);
                sum -= to_int(num[i])-1;
            }

            if(sum<=s){
                break;
            }
        }

        cout<<ans<<endl;

	}

	return 0;
}