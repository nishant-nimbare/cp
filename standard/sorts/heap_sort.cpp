#include <iostream>
#include <vector>
using namespace std;

/**
 *  Max Heap
 * 
 *  remove max element n times and put it at the end of the heap
 * 
 **/


vector<int> heap;
int msize;

int lc(int x) { return ((2*x+1)< msize) ? (2*x+1) : (-1) ;}
int rc(int x) { return ((2*x+2)< msize) ? (2*x+2) : (-1) ;}

int parent(int x) { return ( (x-1)/2 >= 0) ? ((x-1)/2) : (-1) ;}

void shiftUp(int x){

    if( parent(x)!=-1 && heap[x] > heap[parent(x)] ){
        std::swap(heap[x], heap[parent(x)] );
        shiftUp(parent(x));     // recursive keep on shifting up 
    }
}

void shiftDown(int x){
    int left = lc(x), right = rc(x), mmax = x;

    if (left!=-1 && heap[mmax]<heap[left] ) mmax = left;

    if ( right!=-1 && heap[mmax]<heap[right] ) mmax = right;

    if(mmax != x) {
        std::swap(heap[x], heap[mmax] );
        shiftDown(mmax);        // recursive keep on shifting down
    }
}

void heapify(){

    // shiftdown every element that has a child
    // the last child is msize - 1 
    // its parent will be (msize - 1) -1 / 2 = (msize / 2) -1 

    for( int i = (msize/2)-1; i>=0; i--){
        shiftDown(i);
    }

}


void PrintTree(string prefix, int n){

    if( n<0 || n>= msize) return;

    cout<<prefix<<"└──"<<heap[n]<<endl;

    PrintTree(prefix+"  ", lc(n) );
    PrintTree(prefix+"  ", rc(n) );

}


void heapSort(vector<int> &arr){
    heap = arr;
    msize = heap.size();

    heapify();

    while(msize--){
        cout<<" -------- "<<endl;
        PrintTree("",0);
        cout<<" -------- "<<endl;

        std::swap(heap[0], heap[msize] );
        shiftDown(0);
    }

    arr = heap;

}

int main (){

    size_t len = 13;
    srand(time(NULL));
    vector<int> arr;

    for (int i = 0; i < len; i++){
        arr.push_back(rand()%100);
    }

    cout<<" arr before ------------- "<<endl;
    for(int val : arr) cout<<val<<" ";
    cout<<endl;

    heapSort(arr);

    cout<<" heap after --------------- "<<endl;
    for(int val : arr) cout<<val<<" ";
    cout<<endl;


    return 0;
}