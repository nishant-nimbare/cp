#include <bits/stdc++.h>

#define DEBUG true

#ifdef DEBUG
#define dout cout
#else
#define dout 0 && cout
#endif

using namespace std;

int start(vector<vector<int>>& mine) {
    int rows = mine.size();
    int cols = mine[0].size();
    int dp[rows][cols] = {};

    for (int i = 0; i < rows; i++) {
        dp[i][0] = mine[i][0];
    }

    int global_max = INT32_MIN;

    for (int j = 1; j < cols; j++) {
        for (int i = 0; i < rows; i++) {

            dp[i][j] = dp[i][j-1] +  mine[i][j];

            if (i > 0)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + mine[i][j]);

            if (i < rows - 1)
                dp[i][j] = max(dp[i][j], dp[i + 1][j - 1] + mine[i][j]);

            global_max = max(global_max, dp[i][j]);
        }
    }

    return global_max;
}

int main(int argc, char const* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> mine =  {{10, 33, 13, 15},
                  {22, 21, 04, 1},
                  {5, 0, 2, 3},
                  {0, 6, 14, 2}};

    cout << start(mine) << endl;
    return 0;

}