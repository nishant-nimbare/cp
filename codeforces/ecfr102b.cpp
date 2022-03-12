#include <bits/stdc++.h>

// #define DEBUG true

#ifdef DEBUG
#define dout cout
#else
#define dout 0 && cout
#endif

#define PS << " - " <<
#define PG << "  " <<
#define PE << endl

#define F first
#define S second

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

void printVec(string name, vector<int> a) {
    dout << name << " : ";
    for (auto x : a) dout << x << " ";
    dout << endl;
}

// printBT for printing tree horizontally

string root(string str) {
    string root = str;

    while (root.size() > 1) {
        dout PS " r size " PG root.size() PE;

        bool change = false;

        for (int i = 2; i <= (root.size() / 2); i++) {
            dout PS " i " PG i PE;
            if ((root.size() % i) == 0) {
                string sub = root.substr(0, i);
                bool f = true;
                dout PS " sub " PG sub PE;

                for (int j = i; j + i <= root.size(); j += i) {
                    dout PS " cheking" PG sub PG root.substr(j, i) PE;
                    if (!(sub == root.substr(j, i))) {
                        f = false;
                        break;
                    }
                }

                if (f) {
                    // sub is root
                    root = sub;
                    change = true;
                    break;
                }
            }
        }

        if (!change) break;
    }

    if (root.size() == 2) {
        if (root[0] == root[1]) {
            root = root.substr(0, 1);
        }
    }

    if (root.size() == 3) {
        if ((root[0] == root[1]) && (root[0] == root[2])) {
            root = root.substr(0, 1);
        }
    }

    return root;
}

bool divide(string a, string b) {
    bool f = true;
    int i = b.size();
    for (int j = 0; j + i <= a.size(); j += i) {

        if (!(b == a.substr(j, i))) {
            f = false;
            break;
        }
    }

    // cout PS "divides" PG a PG b PG f PE;
    return f;
}

void lcm(string p, string q) {
    string rp = root(p), rq = root(q);

    if (rp != rq) {
        cout << -1 << endl;
        return;
    }

    string lcm;
    if (p.size() >= q.size())
        lcm = p;
    else
        lcm = q;


    while(!(divide(lcm,p) && divide(lcm,q))){
        lcm += rp;
    }

    cout<<lcm<<endl;
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    // cout<< std::fixed << std::setprecision(3)<<ans;
    // std::fstream myfile("./input.txt", std::ios_base::in);

    while (t--) {
        string p, q;
        cin >> p >> q;
        lcm(p,q);
    }

    return 0;
}
