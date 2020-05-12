#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using std::vector;
using std::cin;
using std::cout;
using namespace std;

class JobQueue {
 private:
  int num_workers_;
  vector<int> jobs_;

  vector<int> assigned_workers_;
  vector<long long> start_times_;
   vector<pair<int,long long>> next_free_time;

  void WriteResponse() const {
    for (int i = 0; i < jobs_.size(); ++i) {
      cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
    }
  }

  void ReadData() {
    int m;
    cin >> num_workers_ >> m;
    jobs_.resize(m);
    for(int i = 0; i < m; ++i)
      cin >> jobs_[i];
  }

  void AssignJobs() {

    assigned_workers_.resize(jobs_.size());

    start_times_.resize(jobs_.size());

    next_free_time.clear(); // heap

    // build heap
    int k=0;
    for(int k=0;k<num_workers_;k++){
      next_free_time.push_back(make_pair((int)k,(long long)0));
    }
    
    for (int i = 0; i < jobs_.size(); ++i) {
      int duration = jobs_[i];

      // PrintHeap();

      assigned_workers_[i] = next_free_time[0].first;
      start_times_[i] = next_free_time[0].second;
      next_free_time[0].second += duration;
      
      shiftDown(0);
    }

  }


  int parent(int i){
    return (i-1)/2;
  }

  int lc(int i){
    int l =  (2*i)+1;
    return (l < num_workers_ )?(l):(-1);
  }

  int rc(int i){
    int r =  (2*i)+2;
    return (r < num_workers_ )?(r):(-1);
  }

  int getNext(int l, int r){
    
    if(l==-1 && r==-1)return -1;     // leaf
    
    else if(l!=-1 && r==-1) return l;
    
    else{
      if(next_free_time[l].second < next_free_time[r].second) return l;
      else if(next_free_time[l].second > next_free_time[r].second) return r;
      else if(next_free_time[r].second == next_free_time[l].second){
          if(next_free_time[l].first < next_free_time[r].first) return l;
          else return r;        
      } 
    }
  
    return -1;
  }


  void shiftDown(int i){
    int l = lc(i);
    int r = rc(i);
    int minc = getNext(l,r);
    // cout<<" -- GETNEXT "<<l<<" "<<r<<" = "<<minc<<" \n";
    
      while( (minc!=-1 && getNext(i,minc)!=i )){
      // cout<<" - shifting down "<<data_[i]<<" -> "<<i<<" \n";
      
      swap( next_free_time[i], next_free_time[minc] );
    
      i=minc;
      l = lc(i);
      r = rc(i);    

      minc=getNext(l,r);
    }  
  }

  void PrintHeap(){
    cout<<"Heap is\n";
    int height =  log(next_free_time.size())/log(2);

    if(1<<height >= next_free_time.size()) height++;

    string spaces=" ";
    for(int s=0; s<height; s++) spaces.push_back(' ');

    for(int lvl = 0; lvl<=height; lvl++ ){
  
      for(int i = (1<<(lvl))-1; i< (1<<(lvl+1))-1; i++){

        if(i>=next_free_time.size()) break;

        cout<<(spaces) <<" ("<<(next_free_time[i].first)<<","<<(next_free_time[i].second)<<") ";
      }
      spaces.pop_back();
      cout<<"\n";  
    }
    cout<<"\n";
  }

 public:
  void Solve() {
    ReadData();
    AssignJobs();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  JobQueue job_queue;
  job_queue.Solve();
  return 0;
}
