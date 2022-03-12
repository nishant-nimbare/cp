#include <bits/stdc++.h>

#define DEBUG true

#ifdef DEBUG
#define dout cout
#else
#define dout 0 && cout
#endif

#define PS << " - " <<
#define PG << "  " <<
#define PE << endl

using namespace std;

void printVec(vector<int> a) {
    for (auto x : a) cout << x << " ";
    cout << endl;
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        // dout PS t PE ;

        string str;
        cin >> str;

        int n = str.size(), ob = -1, cb = -1, qms = 0;

        for (int i = 0; i < n; i++) {
            if (str[i] == '(')
                ob = i;
            else if (str[i] == ')')
                cb = i;
            else
                qms += 1;
        }

        if( (cb == 0) || (ob ==n-1) || (qms&1==1) ) {cout<<"NO"<<endl; continue;}

        cout<<"YES"<<endl;

    }

    return 0;
}