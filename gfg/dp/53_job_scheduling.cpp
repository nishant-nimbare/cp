#include <bits/stdc++.h>

#define PS <<" - "<<
#define PG <<"  "<<
#define PE <<endl

using namespace std;


struct Job{
    int startTime, endTime, profit;
    Job(int s, int e, int p=0) : startTime(s), endTime(e), profit(p) {}
};

vector<Job> jobs;


//  WEIGHTED JOB SCHEDULING (dp)
int dp[10000]={};

int nextPossible(int n){

    for(int t=n-1; t>=0; t--){
        if( jobs[t].endTime <= jobs[n].startTime ){
            return t;
        }
    }

    return -1;
}

int nextPossibleBinarySearch(int n){
    int lo = 0, hi = n-1;
    while(lo<hi){
        int mid = lo + (hi-lo)/2 + 1 ;

        if( jobs[mid].endTime > jobs[n].startTime ){
            hi = mid - 1 ;
        }else {
            lo = mid;
        }
    }

    if(jobs[lo].endTime <= jobs[n].startTime) return lo;
    return -1;
}

int go(int n){

    if(n<0) return 0;

    if(dp[n] == -1) {

        /**
         * 2 choices 
         * take current job, recur on next possible
         * recur on next job
         * **/

        int c1 = jobs[n].profit;
        int next = nextPossibleBinarySearch(n);

        if(next != -1) c1 += go( next );

        int c2 = go(n-1);

        dp[n] = max( c1, c2 );
    }
    cout PS n PG dp[n] PE;
    return dp[n];
}

// comparator for sorting jobs : sort by ending time

bool comp(const Job &lhs, const Job &rhs ){
    return (lhs.endTime < rhs.endTime);
}

int WeightedJobScheduling(vector<int> &startTimes, vector<int> &endTimes, vector<int> &profits){

    jobs.clear();
    for(int i =0 ; i<startTimes.size(); i++){
        jobs.push_back(Job(startTimes[i], endTimes[i], profits[i]));
    }

    sort(jobs.begin(), jobs.end(), &comp);

    memset(dp, -1, sizeof(dp));

    return go( jobs.size() - 1 );

}


// UNWEIGHTED JOB SCHEDULING ( greedy )
int UnWeightedJobScheduling(vector<int> &startTimes, vector<int> &endTimes){

    jobs.clear();
    for(int i =0 ; i<startTimes.size(); i++){
        jobs.push_back( Job( startTimes[i], endTimes[i] ) );
    }

    // sort according to endtime
    // pick ele greedily
    sort(jobs.begin(), jobs.end(), &comp);

    int last = 0, total=1;
    for(int i=1; i<jobs.size(); i++){

        if( jobs[last].endTime <= jobs[i].startTime ){
            last = i;
            total+=1;
        }

    }

    return total;
}


int main(int argc, char const *argv[]) {

    vector<int> startTimes =  {1,3,6,2};
    vector<int> endTimes =  {2,5,19,100};
    vector<int> profits =  {50, 20 ,100, 200};

    cout<<WeightedJobScheduling(startTimes, endTimes, profits) PE;

    for(int i=0; i<startTimes.size(); i++) cout<<dp[i]<<" ";
    cout PE; 

    cout << " UnWeighted " PE;
    cout<<UnWeightedJobScheduling(startTimes, endTimes) PE;

    return 0;
}