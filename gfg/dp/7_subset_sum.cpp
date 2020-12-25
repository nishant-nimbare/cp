#include <bits/stdc++.h>

// #define DEBUG true

#ifdef DEBUG
#define dout cout
#else
#define dout 0 && cout
#endif

using namespace std;

int dp[100][1000] = {};

int subsetSum(int n, int sum, vector<int> &arr) {
    dout << " - " << n << " " << sum << endl;

    if (sum == 0) return 1;

    if (n < 0 || sum < 0) return -1;

    if (dp[n][sum] == 0) {
        dp[n][sum] =
            subsetSum(n - 1, sum - arr[n], arr);  // consider current ele

        if (dp[n][sum] != 1)
            dp[n][sum] = subsetSum(n - 1, sum, arr);  // skip cur ele
    }

    return dp[n][sum];
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int sum = 30;

    cout << subsetSum(arr.size() - 1, sum, arr) << endl;

    return 0;
}