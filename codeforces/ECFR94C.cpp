#include <bits/stdc++.h>
using namespace std;

bool isPossible(string s, int x) {
    // s[0..(x-1)] == s[2x .... (3x-1)]

    int size = s.size();
    int l2 = std::min(size, 2 * x);

    if (l2 == size) return true;

    int size2 = std::min(x, size - l2);

    if (s.substr(0, size2) == s.substr(l2, size2)) return true;

    return false;
}

int main(int argc, char const* argv[]) {

    int t;
    cin>>t;

    while (t--) {
        int x;
        string s;

        cin >> s;
        cin >> x;

            /* code */

            if (isPossible(s, x)) {
                int size = s.size();

                string ans(size, '-');

                for (int i = 0; i + x < size; i++) {
                    ans[i] = s[i + x];
                }

                for (int j = 0; j < min(x,size-x) ; j++) {
                    ans[j + x] = s[j];
                }

                for (int k = 0; k < size; k++) {
                    if (ans[k] == '-') ans[k] = '1';
                }

                cout << ans << endl;

            } else {
                cout << "-1" << endl;
            }

    }

    return 0;
}