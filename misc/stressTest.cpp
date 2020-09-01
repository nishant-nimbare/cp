#include <bits/stdc++.h>
#define DEBUG true

#ifdef DEBUG
#define dout cout
#else
#define dout 0 && cout
#endif

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

string prog1(string s, int x) {

    cout<<" -- prog1\n";
    if (isPossible(s, x)) {
        int size = s.size();

        string ans(size, '-');

        for (int i = 0; i + x < size; i++) {
            ans[i] = s[i + x];
        }

        for (int j = 0; j < x; j++) {
            ans[j + x] = s[j];
        }

        for (int k = 0; k < size; k++) {
            if (ans[k] == '-') ans[k] = '1';
        }

        cout << ans << '\n';
        return ans;
    } else {
        cout << "-1" << '\n';
        return "-1";
    }
}

string prog2(string S, int X) {

    cout<<" -- prog2\n";

    int N = int(S.size());
    string W(N, '1');
 
    for (int i = 0; i < N; i++)
        if (S[i] == '0') {
            if (i - X >= 0)
                W[i - X] = '0';
 
            if (i + X < N)
                W[i + X] = '0';
        }
 
    for (int i = 0; i < N; i++) {
        bool one = false;
        one = one || (i - X >= 0 && W[i - X] == '1');
        one = one || (i + X < N && W[i + X] == '1');
 
        if (S[i] != one + '0') {
            cout << -1 << '\n';
            return "-1";
        }
    }
 
    cout << W << '\n';
    return W;
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    srand(time((NULL)));


    while (true) {
        // make test cases till ans is same

        int n = (rand() % 10) + 2;   // 2<= n <= 10^5
        int x = (rand() % (n - 1)) + 1;  // 1<= x <= n-1
        stringstream ss;

        for (int i = 0; i < n; i++) {
            ss << (rand() % 2);
        }

        string s = ss.str();

        cout << " - test - " << s << " " << x << "\n";

        if (prog1(s, x) != prog2(s, x)) {
            break;
        }
    }

    return 0;
}