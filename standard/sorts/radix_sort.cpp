#include <bits/stdc++.h>

#define PS << " - " <<
#define PG << "  " <<
#define PE << endl

using namespace std;

void printVec(vector<int> a) {
    for (auto x : a) cout << x << " ";
    cout << endl;
}

void countSort(vector<int> &arr, int exp) {
    int count[10] = {0};

    for (int i = 0; i < arr.size(); i++) {
        int d = (arr[i] / exp) % 10;
        count[d] += 1;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    vector<int> output(arr.size());

    for (int i = arr.size() - 1; i >= 0; i--) {
        int d = (arr[i] / exp) % 10;

        output[count[d] - 1] = arr[i];
        count[d] -= 1;
    }

    for (int i = 0; i < arr.size(); i++) {
        arr[i] = output[i];
    }
}

void radixSort(vector<int> &arr) {
    int mmax = *max_element(arr.begin(), arr.end());

    for (int exp = 1; mmax / exp > 0; exp *= 10) {
        countSort(arr, exp);
        printVec(arr);
    }
}

int main(int argc, char const *argv[]) {
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66,17, 45, 75, 90, 3, 24, 2, 66, 61, 13, 77, 71, 25};

    radixSort(arr);

    return 0;
}