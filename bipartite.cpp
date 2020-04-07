#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > matrix;

int peeps;
int jobs;

bool assign(int p, int* assignedTo, int seen[]) {
  // try every job for this person
  for (int j = 0; j < jobs; j++) {
    if (matrix[p][j] == 1 && !seen[j]) {
		seen[j] = 1;
		// cout<<" - checked "<<j<<" for "<<p<<" assigned? "<<assignedTo[j]<<'\n';	
      if ((assignedTo[j] == -1) || assign(assignedTo[j], assignedTo, seen)) {
        assignedTo[j] = p;
		// cout<<" - - assigned "<<p<<" to job "<<j<<'\n';
        return true;
      }
    }
  }
  return false;
}

void solve() {

  int assignedTo[jobs];
  int maxMatch = 0;
	memset(assignedTo, -1, sizeof(assignedTo));

  for (int p = 0; p < peeps; p++) {
    int seen[jobs] = {0};

	// cout<<"trying for person "<<p<<'\n';

    if (assign(p, assignedTo, seen)) {
      maxMatch++;
    }
  }

  cout << " matching is ...\n";
  for (int j = 0; j < jobs; j++) {
    cout << j << " -> " << assignedTo[j] << '\n';
  }

  cout << "\n max " << maxMatch << "\n";
}

int main(int argc, char const* argv[]) {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);

  int temp;
//   std::fstream myfile("./input.txt", std::ios_base::in);

  cin >> peeps >> jobs;
  cout << peeps << '\t' << jobs <<'\n';

  for (int i = 0; i < peeps; i++) {
    vector<int> row;

    for (int j = 0; j < jobs; j++) {
      cin >> temp;
	  row.push_back(temp);
    }

	matrix.push_back(row);
  
  }
  
  solve();

  return 0;
}