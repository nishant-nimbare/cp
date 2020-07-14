#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
class Solution {
public:

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int ns1 = nums1.size(), ns2 = nums2.size();
        int total = ns1+ns2;

        int lo = 0, hi = nums1.size();
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;

            // partition with mid no of element of 1st array to left


            int x1,x2,y1,y2;
            x1=y1=INT32_MIN;
            x2=y2=INT32_MAX;

            if( mid > 0 ) x1 = nums1[mid-1];
            if( mid < ns1 ) x2 = nums1[mid];
            

            int ypart = (( total+1 )/2 ) - mid ;

            if(ypart>ns2){
                // we are trying to take more elements from 2nd array than there are available
                // reduce ypart => increase xpart
                lo = mid + 1;
                continue;
            }


            if(ypart < 0){
                // increase ypart => reduce xpart
                hi = mid - 1;
                continue;
            }


            if( ypart > 0 ) y1 = nums2[ ypart - 1];
            if( ypart < ns2 ) y2 = nums2[ ypart ];
        

            cout<<" - "<<lo<<" "<<hi<<" "<<mid<<" "<<ypart<<"\n";

            cout<<" - - "<<x1<<" "<<x2<<" "<<y1<<" "<<y2<<"\n";


            if(x1<=y2 && y1<=x2){
                // solution found

                if(total%2==0){
                    // if(x1!=INT32_MIN && y1!=INT32_MIN){
                    //     return (double)(x1+y1)/(double)2.0;
                    // }else{
                    //     if(x1 == INT32_MIN) x1 = nums2[ypart-2];
                    //     else y1 = nums1[mid-2];
                    //     return (double)(x1+y1)/(double)2.0;
                    // }

                    return (double)(max(x1,y1)+min(x2,y2))/(double)2.0;
                }else{
                    // if(x1!=INT32_MIN && y1!=INT32_MIN)
                        return max(x1,y1) ;
                    
                }
            }
        
            else if(x1 > y2) hi = mid-1;

            else if( y1 > x2) lo = mid+1;

            else{
                cout<<" some unexpected case \n";
            }

        } 

        return (double)(-1.0);
    }
};
// @lc code=end

