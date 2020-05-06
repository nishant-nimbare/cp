#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int count(vector<int> &a, int l, int r, int num) {
    int c = 0;
    for (int i = l; i < r; i++) {
        if (a[i] == num) c++;
    }

    return c;
}

int get_majority_element(vector<int> &a, int left, int right) {
    if (left == right) return -1;
    if (left + 1 == right) return a[left];
    // write your code here
    int m = (left + right) / 2;
    int l = get_majority_element(a, left, m);
    int r = get_majority_element(a, m, right);

    if (l == r) {
        // std::cout << left << " " << right << " returning " << l << '\n';
        return l;
    }

    int lc = count(a, left, right, l);
    int rc = count(a, left, right, r);

    // check majority
    if ((lc > rc) && (((right - left) / 2) < lc)) {
        // std::cout << left << " " << right << " returning " << l << '\n';
        return l;
    }

    if ((lc < rc) && (((right - left) / 2) < rc)) {
        // std::cout << left << " " << right << " returning " << r << '\n';
        return r;
    }

    // return (lc>rc)?(l):(r);
    // std::cout << left << " " << right << " returning -1 \n";
    return -1;
}

int main() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); ++i) {
        std::cin >> a[i];
    }
    std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
