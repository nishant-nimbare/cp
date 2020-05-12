#include <iostream>
#include <string>
#include <vector>

// #define lli long long int

using std::string;
using namespace std;
typedef long long int ull;


ull prime = 1000000007;

ull mod(ull n){
    return ((n%prime)+prime)%prime;
}

ull mpow(ull base, ull exp){

    if( exp == 0 ) return 1;
    
    if( exp == 1 ) return mod(base);

    if( exp&1 ){ //odd
        return mod( mod(base) * mpow( mod(base*base) , exp/2 ) );
    }else{ //even
        return  mod( mpow( mod(base*base) , exp/2 ) );
    }

}

struct Data {
    string pattern, text;
};

Data read_input() {
    Data data;
    std::cin >> data.pattern >> data.text;
    return data;
}

void print_occurrences(const std::vector<int>& output) {
    for (size_t i = 0; i < output.size(); ++i)
        std::cout << output[i] << " ";
    std::cout << "\n";
}

std::vector<int> get_occurrences(const Data& input) {
    const string& s = input.pattern, t = input.text;
    std::vector<int> ans;
    // for (size_t i = 0; i + s.size() <= t.size(); ++i)
    //     if (t.substr(i, s.size()) == s)
    //         ans.push_back(i);


    size_t p = s.length(); 
    ull patHash=0, curHash=0, x = 263;

    for(int i=0; i<p; i++){
        patHash = mod( mod(patHash*x) + (int)s[i] );
        curHash = mod( mod(curHash*x) + (int)t[i] );
    }

    ull x_pow_p = mpow(x, p);  

    if(curHash == patHash && t.substr(0,p) == s ) ans.push_back(0);

    for(int i=p; i<t.length(); i++){

        curHash = mod( mod(curHash*x)  + t[i] - mod(t[i-p]*x_pow_p));

        if(curHash == patHash && t.substr(i-p+1,p) == s ) ans.push_back(i-p+1);

    }

    return ans;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    print_occurrences(get_occurrences(read_input()));
    return 0;
}
