#include<bits/stdc++.h>
using namespace std;


class CustomStack {
    
    vector<int> mstack;
    vector<int> incr;
    int size, top;
public:
    CustomStack(int maxSize) {
        mstack.resize(maxSize, 0);

        // incr.clear();
        incr.resize(maxSize, 0);
        
        top=-1;
        size= maxSize;
    }
    
    void push(int x) {
        if(top < size-1 ){
            top+=1;
            mstack[top] = x;
        }
    }
    
    int pop() {
        if(top > -1){
            // curIncr += incr[top];
            int val = mstack[top] + incr[top];
            
            if(top!=0) incr[top-1] += incr[top];
            
            top-=1;
            return val;
        
        }
        
        return -1;
    }
    
    void increment(int k, int val) {
        
        if(k>top) k=top;
        else k = k-1;

        if(k!=-1) incr[k] += val; 
    }
};

/**
 
 * ["CustomStack","push","pop","increment","pop","increment","push","pop","push","increment","increment","increment"]
[[2],[34],[],[8,100],[],[9,91],[63],[],[84],[10,93],[6,45],[10,4]]
 * 
 */



int main(){

    CustomStack* obj = new CustomStack(2);
    obj->push(34);
    // obj->push(2);
    cout<<obj->pop()<<"\n";
    obj->increment(8,100);
    cout<<obj->pop()<<"\n";
    obj->increment(9, 91);
    obj->push(63);
    cout<<obj->pop()<<"\n";
    obj->push(84);
    obj->increment(10,93);
    obj->increment(6,45);
    obj->increment(10,4);
}