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

#define MAXN 1000
using namespace std;

unsigned short int inf = MAXN + 10;
// min num of ele req to reach sum = k out of the first n ele
// int dp[4000+1][4000 + 1] = {-1};
unsigned short int dp[MAXN + 1][MAXN + 1][(MAXN/2) + 1];

void printVec(string name, vector<int> a) {
    dout << name << " : ";
    for (auto x : a) dout << x << " ";
    dout << endl;
}

int  get( int i, int a, int b){
    if( b>a) return get(i, b, a);
    return dp[i][a][b];
}

int knapsack2(vector<int> ele, int k) {
    int n = ele.size();

    // we can't reach any +ve k with 0 ele
    for (int i = 0; i <= k; i++)
        for (int j = 0; j <= i; j++) dp[0][i][j] = inf;

    // we can reach sum = 0 with min req eles = 0
    for (int i = 0; i <= n; i++) {
        dp[i][0][0] = 0;
        if (i > 0) {
            for (int j = 1; j <= k; j++) {
                if (ele[i - 1] >= j) {
                    // dout PS i PG j
                    dp[i][j][0] = 1;
                    // dp[i][0][j] = 1;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int a = 0; a <= k; a++) {
            for (int b = 0; b <= a; b++) {

                /**
                 *  3 choices
                 * dont put ith block anywhere
                 * put on 1st stack (a)
                 * put on 2nd stack (b)
                 * **/

                //c1
                dp[i][a][b] = get(i - 1,a,b);

                unsigned short int c2=inf, c3=inf;

                if (ele[i - 1] >= a){
                    // c2 = dp[i-1][0][b] + 1;
                    c2 = get(i-1, 0, b) + 1;
                }else{
                    // c2 = dp[i-1][a-ele[i-1]][b] + 1;
                    c2 = get(i-1,a-ele[i-1],b) + 1;
                }

                if( ele[i-1] >= b) {
                    // c3 = dp[i-1][a][0] + 1;
                    c3 = get(i-1,a,0) + 1;
                }else{
                    // c3 = dp[i-1][a][b-ele[i-1]] + 1;
                    c3 = get(i-1,a,b-ele[i-1]) + 1;
                }

                dp[i][a][b] = min(dp[i][a][b], min(c2, c3));

            }
        }
    }

    dout << " knapsack table :- " << endl;
    for (int i = 1; i <= n; i++) {
        dout << i << " :- " << endl;
        for (int a = 0; a <= k; a++) {
            for (int b = 0; b <= a; b++) {
                dout << ((dp[i][a][b] == inf) ? (-2) : (dp[i][a][b])) << " ";
            }
            dout << endl;
        }
        dout << endl;
    }

    if(dp[n][k][k] == inf) return -1;

    return dp[n][k][k];
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    // cout<< std::fixed << std::setprecision(3)<<ans;
    // std::fstream myfile("./input.txt", std::ios_base::in);

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> arr(n);

        for (int &x : arr) cin >> x;
        printVec("arr ", arr);

        // memset(dp, inf, sizeof(dp));
        for (int i = 0; i <= n; i++) {
            for (int a = 0; a <= k; a++) {
                for (int b = 0; b <= k; b++) {
                    dp[i][a][b] = inf;
                }
            }
        }

        cout << knapsack2(arr, k) << endl;
        dout<<endl<<endl<<" --------------------------------- "<<endl<<endl;
        // vector<int> blk1 = knapsack(arr, k);
        // printVec("block 1 ", blk1);

        // vector<int> rem;

        // sort(arr.begin(), arr.end());
        // sort(blk1.begin(), blk1.end());

        // std::set_difference(arr.begin(), arr.end(), blk1.begin(), blk1.end(),
        //                     std::inserter(rem, rem.begin()));

        // printVec("rem ", rem);

        // dout << endl << endl;

        // memset(dp, -1, sizeof(dp));

        // vector<int> blk2 = knapsack(rem, k);
        // printVec("block 2 ", blk2);

        // cout << (blk1.size() + blk2.size()) << endl;
    }

    return 0;
}
