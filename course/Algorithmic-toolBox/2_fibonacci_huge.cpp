#include <iostream>
#define lli long long int
using namespace std;

// DONE

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}


lli fibo_huge(lli n, lli m){

    int hash[m*m]={0};
    hash[1]=1;
    lli period =0;

    for(lli i=0; i<m*m; i++){
        hash[i+2] = (hash[i+1] + hash[i])%m;
        if( ( hash[i+1]==0 ) && ( hash[i+2]==1 )){
            period = i+1;
            break;
        }
    }

    // cout<<" period "<<period<<"\n";

    lli temp = n%period;
    return hash[temp];

}

int main() {
    lli n, m;
    std::cin >> n >> m;
    std::cout << fibo_huge(n, m);
}
