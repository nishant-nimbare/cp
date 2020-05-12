#include <iostream>
#include <vector>
#include <deque> 

using std::cin;
using std::cout;
using std::vector;
using std::max;

void print(std::deque<int> &maxx){
    for(int i:maxx) 
        cout<<i<<" ";

    cout<<"\n";
}


void max_sliding_window_naive(vector<int> const & A, int w) {
    for (size_t i = 0; i < A.size() - w + 1; ++i) {
        int window_max = A.at(i);
        for (size_t j = i + 1; j < i + w; ++j)
            window_max = max(window_max, A.at(j));

        cout << window_max << " ";
    }

    return;
}

void fast(vector<int> const & A, int w){
    std::deque<int> maxx;
    int i=0,j=0;

    int sm=-1;
    //1st block
    while(j<w){
        
        if( ( maxx.empty() ) || ( maxx.back() >= A[j] ) ) 
            maxx.push_back(A[j]);
        else{ 
            while( !maxx.empty() && maxx.back() < A[j] )
                maxx.pop_back();
            
            maxx.push_back(A[j]);
        }
        // sm= std::max(sm,A[j]);

        j+=1;
    }

    // maxx.push_back(sm);

    cout<< maxx[0]<< " ";
    // maxx.pop_front();


    i=1; j=w;
    while(j<A.size()){

        // cout<<" deque - ";
        // print(maxx);

        // inserting
        if( ( maxx.empty() ) || ( maxx.back() >= A[j] ) ) 
            maxx.push_back(A[j]);
        else{
            while( !maxx.empty() && maxx.back() < A[j] )
                maxx.pop_back();
        
            maxx.push_back(A[j]);
        } 
        

        // removing
        if(A[i-1] == maxx.front()) 
            maxx.pop_front();

        cout<< maxx[0]<< " ";

        i+=1;
        j+=1;
    }
}


int main() {
    int n = 0;
    cin >> n;

    vector<int> A(n);
    for (size_t i = 0; i < n; ++i)
        cin >> A.at(i);

    int w = 0;
    cin >> w;

    fast(A, w);

    return 0;
}
