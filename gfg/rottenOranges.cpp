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

using namespace std;

void PrintQ( list<pair<int, int>> q){

    dout <<" Q : ";
    for(auto t : q){
        dout<< " (" << t.first <<", "<< t.second << "), \t";
    }
    dout<<endl;
}

int rot(vector<vector<int>> mmap) {
    int R = mmap.size(), C = mmap[0].size();
    list<pair<int, int>> q;

    // push all rotten oranges in queue;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (mmap[i][j] == 2) {
                // this is rotten
                q.push_back({i, j});
            }
        }
    }

    q.push_back({-1, -1});  // delimiter

    int MAX_ITR = 15;
    int time = 0;
    while ( (q.size() ) && (MAX_ITR--)) {

        PrintQ(q);

        pair<int, int> cur = q.front();
        q.pop_front();

        if (q.size() == 0) {
            break;
        }

        if (cur.first == -1 && cur.second == -1) {
            time++;
            q.push_back({-1, -1});
            continue;
        }

        // check if cur has fresh neighbours

        dout << (" C : " ) << (cur.first) PG cur.second PE;

        if ((cur.first > 0) && (mmap[cur.first - 1][cur.second] == 1)) {
            mmap[cur.first - 1][cur.second] = 2;
            q.push_back({cur.first - 1, cur.second});
            dout PS " - pushing " PG cur.first-1 PG cur.second PE;
        }

        if ((cur.first < R - 1) && (mmap[cur.first + 1][cur.second] == 1)) {
            mmap[cur.first + 1][cur.second] = 2;
            q.push_back({cur.first + 1, cur.second});
            dout PS " - pushing " PG cur.first + 1 PG cur.second PE;
        }

        if ((cur.second > 0) && (mmap[cur.first][cur.second - 1] == 1)) {
            mmap[cur.first][cur.second - 1] = 2;
            q.push_back({cur.first, cur.second - 1});
            dout PS " - pushing " PG cur.first PG cur.second-1 PE;
        }

        if ((cur.second < C - 1) && (mmap[cur.first][cur.second + 1] == 1)) {
            mmap[cur.first][cur.second + 1] = 2;
            q.push_back({cur.first, cur.second + 1});
            dout PS " - pushing " PG cur.first PG cur.second+1 PE;
        }
    }

    // check if all have rotten

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (mmap[i][j] == 1) {
                // this is fresh
                return -1;  // not possible to rot all oranges
            }
        }
    }

    return time;
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << rot(vector<vector<int>>{
                {2, 1, 0, 2, 1},
                {0, 0, 1, 2, 1},
                {1, 0, 0, 2, 1}
            })
         << endl;

    return 0;
}
