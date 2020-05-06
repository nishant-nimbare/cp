#include <bits/stdc++.h>
using namespace std;

long long int MaxPairwiseProduct(const std::vector<int>& numbers) {
    int a = INT_MIN, b = INT_MIN;

    for (int k : numbers) {
        if (k > a) {
            b = a;
            a = k;
        }
        else if(k>b){
            b=k;
        }
    }

    return (long long int)a*b;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;
}
