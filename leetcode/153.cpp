#include<bits/stdc++.h>
using namespace std;


int findMin(vector<int> nums) {
        
        if(nums.size()==1) return nums[0];

        int lo=0, hi=nums.size()-1;
        int mmin = INT32_MAX;
        while(lo<=hi){
            
            int mid = lo+(hi-lo)/2;
            
            if(nums[lo] <= nums[mid]){
                // lo - mid is sorted correct
                mmin = min(mmin, nums[lo] );
                lo = mid+1;
            }
            else if( nums[mid] <= nums[hi] ){
              // mid - hi is sorted correct
                mmin = min(mmin, nums[mid] );
                hi = mid -1;
            }
            
        }
        
        return mmin;
        
}



int main(){

    cout<<findMin(vector<int> {2,1})<<"\n";
}