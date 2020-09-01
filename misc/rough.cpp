#include <iostream>
using namespace std;

int main() {
    int n = 4;

    while (n <= 15) {
        int ans = 0;

        for (int i = 0; i < n - 3; i++) {
            for (int j = i + 1; j < n - 2; j++) {
                for (int k = j + 1; k < n - 1; k++) {
                    for (int l = k + 1; l < n; l++) {
                        ans++;
                    }
                }
            }
        }
        cout << n << " " << ans << "\n";
        n++;
    }

    return 0;
}