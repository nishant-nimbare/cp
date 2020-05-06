#include <iostream>
#define lli long long int
using namespace std;

// DONE 

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}



lli fibo_huge(lli n, lli m){

    int hash[m*m]={0};
    hash[1]=1;
    lli period =0, psum=1; // 0+1


    for(lli i=0; i<m*m; i++){
        hash[i+2] = (hash[i+1] + hash[i])%m;
        psum += hash[i+2];
        psum = psum%m;

        if( ( hash[i+1]==0 ) && ( hash[i+2]==1 )){
            period = i+1;
            psum--; // remove extra 1 from the next epoch
            if(psum<0) psum+=m; 
            break;
        }
    }

    // cout<<" period "<<period<<" psum "<< psum <<"\n";
    lli sld = ((n/period)*psum)%m;
    lli temp = n%period;

    for(lli i=0; i<=temp; i++){
        sld = (sld+hash[i])%m;
    }
    
    return sld;
}


int main() {
    lli n = 0;
    std::cin >> n;
    std::cout << fibo_huge(n,10);
}
