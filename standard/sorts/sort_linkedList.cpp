#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


struct Node{
    int val;
    Node * next;
    Node(int d): val(d){};
};


Node* split(Node* head){
    Node *s=head, *f=head;

    while(f->next){
        f=f->next;
        if(f->next){
            s=s->next;
            f=f->next;
        }
    }

    // s will be middle
    Node* m = s->next;
    s->next = nullptr; //cut list into 2

    return m;
}

Node* merge(Node * a, Node * b){

    if(!a) return b;
    if(!b) return a;

    Node * t;

    if(a->val < b->val){
        t=a;
        t->next = merge(a->next, b);
    }else{
        t=b;
        t->next = merge(a, b->next);
    }

    return t;
}


Node* merge_sort(Node* head){

    if( !head || !head->next ) return head;

    Node* mid = split(head);

    // recurvisly divide 
    head = merge_sort(head);

    mid = merge_sort(mid);

    return merge(head, mid);
}



int main(){
    
    vector<int> test = {10,9,11,7,6,5,4,3,2,1};

    Node* dummy = new Node(-1), *prev = dummy;



    for(int k=0; k<test.size(); k++){
        
        prev->next = new Node((rand()%100));
        prev = prev->next;
    
    }

    dummy->next = merge_sort(dummy->next);

    Node* t = dummy->next;

    while(t){ 
        cout<<t->val<<" ";
        t = t->next;     
    }
    
    return 0;
}