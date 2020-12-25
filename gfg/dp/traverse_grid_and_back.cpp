#include <bits/stdc++.h>

#define DEBUG true

#ifdef DEBUG
#define dout cout
#else
#define dout 0 && cout
#endif

#define vec vector<int>
using namespace std;

// https://www.geeksforgeeks.org/maximum-points-top-left-matrix-bottom-right-return-back/

/**
 * the problem cannot be divided into 2 seperate dp traversals as the optimal
 * soln = 1st traversal + 2nd traversal but the 2nd traversal depend on the 1st
 * traversal
 *
 * therefore the global optimal soln may not contain the optimal 1st traversal
 *
 *
 * the ans is calculated by considering both paths simultaneouly
 *
 * we calculate both paths from 0,0 to n-1,m-1
 *
 *
 * **/

vector<vector<int>> mat;
int N, M;

int dp[100][100][100] = {-1};

// max possible cost = 100*100
const int inf = 100000;


void print(vec v){
    for(auto x: v) cout<<x<<" ";
    cout<<endl;
}

int cost(int x1, int y1, int x2, int y2) {
    if (x1 == x2 && y1 == y2) {
        if (mat[x1][y1] == 1) return 1;
    }

    return mat[x1][y1] + mat[x2][y2];
}

/**
 * we can reduce state variable to 3 instead of 4 because x1+y1 = x2+y2
 *
 * **/
int go(int x1, int y1, int x2) {
    int y2 = x1 + y1 - x2;

    if (x1 == N - 1 && x2 == N - 1 && y1 == M - 1 && y2 == M - 1) return 0;

    if (x1 > N || x2 > N || y1 > M || y2 > M) return (-1 * inf);

    /**
     * possible combinations
     *  Path-1  Path-2
     *  right   right
     *  right   down
     *  down    right
     *  down    down
     * **/

    if (dp[x1][y1][x2] == -1) {
        int a=(-1 * inf), b=(-1 * inf), c=(-1 * inf), d=(-1 * inf);

        if ((y1 < M - 1 && mat[x1][y1 + 1] != -1) &&
            (y2 < M - 1 && mat[x2][y2 + 1] != -1)) {
            a = cost(x1, y1 + 1, x2, y2 + 1) + go(x1, y1 + 1, x2);
        }

        if ((y1 < M - 1 && mat[x1][y1 + 1] != -1) &&
            (x2 < N - 1 && mat[x2 + 1][y2] != -1)) {
            b = cost(x1, y1 + 1, x2 + 1, y2) + go(x1, y1 + 1, x2 + 1);
        }

        if ((x1 < N - 1 && mat[x1 + 1][y1] != -1) &&
            (y2 < M - 1 && mat[x2][y2 + 1] != -1)) {
            c = cost(x1 + 1, y1, x2, y2 + 1) + go(x1 + 1, y1, x2);
        }

        if ((x1 < N - 1 && mat[x1 + 1][y1] != -1) &&
            (x2 < N - 1 && mat[x2 + 1][y2] != -1)) {
            d = cost(x1 + 1, y1, x2 + 1, y2) + go(x1 + 1, y1, x2 + 1);
        }

        dp[x1][y1][x2] = max(max(a, b), max(c, d));

    // cout<<" - ";
    // print(vec {x1, y1, x2, y2, dp[x1][y1][x2] });
 
    }
 
    return dp[x1][y1][x2];
}

int main() {
    // mat = {{0, 1, 0, 1, 0},
    //        {1, -1, -1, -1, 0},
    //        {1, 0, 1, 0, 1},
    //        {0, -1, -1, -1, 1},
    //        {0, 1, 0, 1, 0}
    //     };

    // N = mat.size();
    // M = mat[0].size();


    cin>>N>>M;


    for(int i=0; i<N; i++){
        vec row;
        for(int j=0; j<M; j++){
            int t;
            cin>>t;
            row.push_back(t);
        }
        mat.push_back(row);
    }

    memset(dp, -1, sizeof(dp));

    cout<<dp[N-1][M-1][N-1]<<endl;

    cout<< go(0,0,0) <<endl;
}