#include <bits/stdc++.h>

// #define DEBUG true

#ifdef DEBUG
#define dout cout
#else
#define dout 0 && cout
#endif

using namespace std;

const int MAXS = 1000;

unsigned int dpC[MAXS][MAXS] = {};

unsigned int dpR[MAXS][MAXS] = {};

// nCr = n-1Cr-1 + n-1Cr
int ncr(int n, int r) {
    if (r == 0 || n == r) return 1;

    if (dpC[n][r] == 0) dpC[n][r] = ncr(n - 1, r - 1) + ncr(n - 1, r);

    return dpC[n][r];
}

// nPr = r*(n-1Pr-1) + n-1Pr
int npr(int n, int r) {
    dout << " - - " << n << " " << r << endl;

    if (r > n) return 0;
    if (r == 0) return 1;

    if (dpR[n][r] == 0) dpR[n][r] = r * npr(n - 1, r - 1) + npr(n - 1, r);

    return dpR[n][r];
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    srand(time(NULL));

    while (t--) {
        int n = rand() % 20, r = rand() % n + 1;

        cin >> n >> r;
        cout << " - " << n << " " << r << endl;
        // cout<<ncr(n,r)<<endl;
        cout << npr(n, r) << endl;
    }

    return 0;
}