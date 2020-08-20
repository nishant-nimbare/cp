#include <iostream>
#include <vector>
using namespace std;

/**
 *  Min Heap
 * 
 *  0 base indexing
 * 
 * 
 *  Left child : 2x + 1
 *  right child : 2x + 2
 *  parent : x-1/2
 * 
 * 
 **/

vector<int> heap;
int msize;

int lc(int x) { return ((2*x+1)< msize) ? (2*x+1) : (-1) ;}
int rc(int x) { return ((2*x+2)< msize) ? (2*x+2) : (-1) ;}

int parent(int x) { return ( (x-1)/2 >= 0) ? ((x-1)/2) : (-1) ;}

void shiftUp(int x){

    if( parent(x)!=-1 && heap[x] < heap[parent(x)] ){
        std::swap(heap[x], heap[parent(x)] );
        shiftUp(parent(x));     // recursive keep on shifting up 
    }
}

void shiftDown(int x){
    int left = lc(x), right = rc(x), mmin = x;

    if (left!=-1 && heap[mmin]>heap[left] ) mmin = left;

    if ( right!=-1 && heap[mmin]>heap[right] ) mmin = right;

    if(mmin != x) {
        std::swap(heap[x], heap[mmin]);
        shiftDown(mmin);        // recursive keep on shifting down
    }
}

void heapify(){

    msize = heap.size();

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

int main (){

    msize = 13;
    srand(time(NULL));

    for (int i = 0; i < msize; i++){
        heap.push_back(rand()%100);
    }

    cout<<" heap before"<<endl;
    PrintTree("", 0);
    cout<<endl;

    heapify();

    cout<<" heap after"<<endl;
    PrintTree("", 0);
    cout<<endl;


    return 0;
}