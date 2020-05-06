#include <iostream>
#define lli long long int
using namespace std;

//done

int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
    }

    return sum % 10;
}

int faster(lli n){
    int hash[61] = {0};
    hash[1] = 1;

    int psum = 1; // 0+1

    lli t1=1,t2=0,t;
    for(lli i =2; i<=60; i++){
        t = (t1+t2) %10;
        hash[i] = (t*t)%10;
        psum = (psum+hash[i])%10;

        t2=t1;
        t1=t;
    }

    // cout<< " psum "<<psum<<"\n"; 

    int sum = ((n/60)*psum)%10;
    n = n%60;
    for(int i=0; i<=n; i++){
        sum = (sum + hash[i])%10;
    }

    return sum;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << faster(n);
}
