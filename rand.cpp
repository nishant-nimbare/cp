#include <bits/stdc++.h>

using namespace std;

void mmerge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    vector<int> res;
    int i, j = 0;
    cout << "out" << m << n << '\n';

    while(i<m)

    while ((i < m) && (j < n)) {
        cout << " inside ..\n";
        if (nums1[i] <= nums2[j]) {
            res.push_back(nums1[i]);
            i++;
        } else {
            res.push_back(nums2[j]);
            j++;
        }
    }

    cout << "out" << m << n << '\n';

    //         while(i<m) res.push_back(nums1[i++]);

    //         while(j<n) res.push_back(nums2[j++]);

    nums1 = res;
}

int main(int argc, char const* argv[]) {
    vector<int>b {1, 3, 5};
    vector<int>a {2, 4, 6};
    mmerge(a, 3, b, 3);

    return 0;
}
