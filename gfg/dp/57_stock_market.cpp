// best-time-to-buy-and-sell-stock

#include <bits/stdc++.h>

#define DEBUG true

#ifdef DEBUG
#define dout cout
#else
#define dout 0 && cout
#endif

using namespace std;

int inf = 1000000000;


// once transaction
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
//time n ,space 1
int stock1kadanes(vector<int>& prices) {

    /**
     * if we convert the arr to difference of ele and prev ele
     * {1, 7, 4, 11} ==> {0, 6, -3, 7}
     * 
     * the problem becomes max sum subarray (kadanes)
     * **/

    int local_max = 0, global_max = 0;

    for(int i=1; i<prices.size(); i++){
    
        local_max += prices[i]-prices[i-1];
        local_max = max( 0 ,  local_max);
        global_max = max( global_max, local_max);
    }

    return global_max;
}


// time n, space n
int stock1(vector<int>& prices) {

    vector<int> stac; // monotonic increasing
    
    int mmax = INT32_MIN;
    for(int i=0; i<prices.size(); i++){
        
        while(!stac.empty() && stac.back() > prices[i]){
            stac.pop_back();
        }
        stac.push_back(prices[i]);
        mmax = max(mmax, stac.back()- stac.front());
    }
    
    if(mmax < 0) mmax= 0;
    return mmax;
}


// infinite transaction
// time n, space 1
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
int stock2(vector<int>& prices){
    int ans = 0;
    
    for(int i=1; i<prices.size(); i++){
        if(prices[i]>prices[i-1]){
            ans += prices[i]-prices[i-1];
        }
    }
    return ans;
}



// atmost k transactions
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

int dp[1000][1000][2];
// i=day, j=transaction<=k, l=0 stock holding / l=1 stock not holding

int stock3(vector<int> prices,int k){

    int n=prices.size();

    if(n<=0 || k<=0 ) return 0;

    if(2*k>=n){
        //we can do n/2 buys and n/2 sells
        return stock2(prices);
    }


    // initializing
    for(int i=0; i<n; i++){
        for(int j=0; j<=k; j++){
            dp[i][j][0] = -1*inf;
            dp[i][j][1] = -1*inf;
        }
    }

    dp[0][0][0] = 0; // not buying on day 0
    dp[0][1][1] = -prices[0]; //buying on day 0

    for(int i=1; i<n; i++){
        for(int j=0; j<=k; j++){

            // 4 possible options
            // if cur holding :  keep holding, buy ( so that current is holding)
            // if not holding : keep not holding, sell ( so cur becomes not holding) 
            
                           // hold              // buy , counts as +1 transaction 
            if (j > 0)
            dp[i][j][1] = max( dp[i-1][j][1], dp[i-1][j-1][0] - prices[i] ); 

                            // not hold         // sell , doesn't count as seperate transaction
            dp[i][j][0] = max( dp[i-1][j][0], dp[i-1][j][1] + prices[i] ); 
        }
    }


    int global_max = -1*inf;
    // since atmost k transaction
    // find max ans over all j
    for(int j=0; j<=k; j++){
        global_max = max(global_max, dp[n-1][j][0] );        
    }

    return global_max;

}


//time n, space 1
//https://www.geeksforgeeks.org/maximum-profit-by-buying-and-selling-a-stock-at-most-twice-set-2/
int stockOnly2Transactions(vector<int>& prices){


    int buy1 = inf , buy2 = inf , profit1 = -1*inf , profit2= -1*inf;

    /**
     * buy 1 & 2 tracks the ideal buying points for 1 st and 2nd  transactions
     * we want to minimise buy1 and buy2
     * 
     * profit 1 & 2 tracks max values of profit 1st and 2nd transactions : maximise
     * 
     * **/

    for(int  i=0; i<prices.size(); i++){

        // buying 1st at i
        buy1 = min(buy1, prices[i]);

        // selling 1st at i
        profit1 = max( profit1, prices[i]-buy1);

        // buying 2st at i
        buy2 = min( buy2, prices[i] - profit1 );

        // selling 2st at i
        // profit 2 is total profit
        profit2 = max(profit2, prices[i] - buy2);
     

    }
    return profit2;

}


//k transaction 
// time nk, space n
int stockK(vector<int>  prices, int k){

    // using stockOnly2Transactions approach
    int n = prices.size();
    vector<int> prevProfit( n ,0 ),  curProfit( n,0 );

    for( int j=0; j<k; j++){
        
        int buy = inf, profit = -1*inf; 
        
        for(int i=0; i<n; i++){

            // buy
            buy = min ( buy, prices[i]-prevProfit[i] );

            profit = max( profit, prices[i] - buy ); 

            curProfit[i] = profit;
        
        }

        swap(curProfit, prevProfit); // swapping between 2 arrays only (not storing for all k transactions)
    }

    return prevProfit[n-1];
}

int main(){

    vector<int> prices = {7,1,5,3,1,6,4};

    // cout<<stock1(prices)<<endl;
    // cout<<stock1kadanes(prices)<<endl;

    // cout<<stock2(prices)<<endl;

    cout<<stock3( prices, 2)<<endl;

    cout<<stockK( prices, 2)<<endl;

    cout<<stockOnly2Transactions(prices) <<endl;

    return 0;
}