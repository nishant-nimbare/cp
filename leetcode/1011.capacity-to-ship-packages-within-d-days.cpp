#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1011 lang=cpp
 *
 * [1011] Capacity To Ship Packages Within D Days
 */

// @lc code=start
class Solution {
public:


    int rangeSum(vector<int>& pre, int i, int j){
        if(j==0) return pre[i];

        return (pre[i]-pre[j-1]);
    }

    bool possible(vector<int>& pre, int D, int cap){

        ///check if it is possible to ship
        // cout<<" checking for "<<D<<" "<<cap<<"\n";

        int i=0, j=0;
        for(; i<pre.size(); i++){

            while( rangeSum(pre, i, j) > cap ){
                // cout<<" - fittng b/w "<<j<<" "<<i<<"\n";
                j=i;
                if(D==0) return false; 
                D--;
            }
        }


        // cout<<" - - outside "<<j<<" "<<i<<"\n";

        if(j<pre.size() && D==0) return false;

        return true;
    }

    int shipWithinDays(vector<int>& weights, int D) {
        int sum = 0;
        vector<int> pref;
        for(auto w:weights){
            sum+=w;
            pref.push_back(sum);
        }

        // binary search capacity
        int l = 0, r=pref.back();

        while(l<r){
            int mid = l + (r-l)/2 ;

            if(possible(pref,D, mid)){
                r = mid - 1;
            }else{
                l = mid + 1;
            }    

        }
        cout<<(r+1)<<" - \n";

        if(possible(pref, D, r)) return r;

        return (r+1);    
    }
};
// @lc code=end



int main(){

    vector<int> pref = {1,2,3,4,5,6,7,8,9,10};
    Solution obj;
    cout<<obj.possible(pref, 3, 4);   
}