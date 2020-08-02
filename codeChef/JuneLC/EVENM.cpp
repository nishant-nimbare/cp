#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int t;
	cin>> t;
	
	while(t--){
		int n, count=1;
		cin >> n;
        int dir = -1;
        int start, end;
        int mat[n][n];

        for (int row = 0; row < n; row++) {
            dir *=-1;
            int i = (dir == 1)?(0):(n-1);

            while(0<=i && i<=n-1){
            
                mat[row][i] = count++;
                i += dir;
            }			
		} 


        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                cout<<mat[r][c]<<" ";
            }
            cout<<"\n";
        }
	
    }
	return 0;
}