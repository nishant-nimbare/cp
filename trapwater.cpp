#include <bits/stdc++.h>

using namespace std;

int trap(vector<int>& height) {
    int total = 0;
    vector<int> stac;  // index

    for (int i = 0; i < height.size(); i++) {
        while (!stac.empty() && stac.back() <= height[i]) {
            // depression found
            int base = height[stac.back()];
            stac.pop_back();

            if (stac.empty()) {
                // there is no left wall
                break;
            }

            int h = std::min(height[i], height[stac.back()]) - base;

            int l = i - stac.back() - 1;

            cout << " b/w " << stac.back() << " - " << i << " : adding "
                 << h * l << "\n";

            total += h * l;
        }

        if (!stac.empty())
            cout << " - stac back : " << height[stac.back()] << " " << height[i]
                 << "\n";

        stac.push_back(i);
    }

    return total;
}

int main(){
    vector<int> a =  {0,1,0,2,1,0,1,3,2,1,2,1};

    cout<<trap(a)<<"\n";
}