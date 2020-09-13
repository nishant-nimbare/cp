#include <bits/stdc++.h>

// #define DEBUG true

#ifdef DEBUG
#define dout cout
#else
#define dout 0 && cout
#endif

#define lli long long int

using namespace std;

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        long long int a, b, x, y, n;
        cin >> a >> b >> x >> y >> n;

        long long int best = a * b;

        lli a1, a11, b1, b11;

        a1 = max(a - n, x);
        // if (n >= a1)
        b1 = max(b - (n - (a - a1)), y);
        // else
        //     b1 = b;

        dout << " - " << a1 << " " << b1 << endl;

        best = min(best, a1 * b1);

        b11 = max(b - n, y);

        // if (n >= b11)
        a11 = max(a - (n - (b - b11)), x);
        // else
        //     a11 = a1;

        best = min(best, a11 * b11);

        dout << " - " << a11 << " " << b11 << endl;

        cout << best << endl;
    }

    return 0;
}