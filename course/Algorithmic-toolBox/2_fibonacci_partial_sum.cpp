#include <iostream>
#include <vector>
#define lli long long int
using namespace std;

// done

lli get_fibonacci_partial_sum_naive(lli from, lli to) {
    lli sum = 0;

    lli current = 0;
    lli next  = 1;

    for (lli i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        lli new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}

int faster(lli from, lli to){

    // pisano period of 10 = 60
    // sum of that period is 0

    int hash[61] = {0};
    // int hsum[61] = {0};

    hash[1]=1;
    // hsum[1]=1;

    for(int i=2; i<=60; i++){
        hash[i] = ( hash[i-1] + hash[i-2] ) %10;
        // hsum[i] = ( hsum[i-1] + hash[i] ) %10;
    }


    from = from%60;
    to=to%60;
    int sum=0;

    for(int i=from; i<=60; i++) sum = ( sum + hash[i] )%10;

    // cout<<" sum 1st half "<<sum<<" "<<( 10 - hsum[from])<<" \n";

    for(int i=1; i<=to; i++) sum = ( sum + hash[i] )%10; 


    return sum;
}


int main() {
    lli from, to;
    std::cin >> from >> to;
    std::cout << faster(from, to);
}
