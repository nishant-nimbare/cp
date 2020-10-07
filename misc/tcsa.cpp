#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {


    int n, m, r;
    cin >> n >> m >> r;

    int totalIn = 0, totalOut = 0;

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        // totalIn += max(0, temp - r);
        totalIn += temp-r;
    }

    for (int i = 0; i < m; i++) {
        int temp;
        cin >> temp;
        // totalOut += max(0, temp - r);
        totalOut += temp-r;
    }

    int ans = (totalOut - totalIn);

    if (ans == 0)
        cout << "BALANCED";
    else {
        if (ans > 0)
            ans += r;
        else
            ans -= r;

        cout << ans;
    }
    return 0;
}