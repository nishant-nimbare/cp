#include <bits/stdc++.h>
using namespace std;

/***
 * To find whether Single LL is palindrom 
 * 1. Use Stack o(n) space
 * 2. Or Split LL in 2 reverse 2nd half and compare
 * ***/


struct Node{
    int val;
    Node* next;
    Node(int v):val(v){}
};

// split

Node * split(Node * head){

    Node * slow = head, * fast=head;

    while(fast->next){
        fast = fast->next;
        if(fast->next){
            fast = fast->next;
            slow = slow->next;
        }
    }    

    Node * middle = slow->next;
    slow->next = NULL; //split
    return middle;
}


// reverse
Node * reverse(Node* head){

    if(!head || !head->next) return head; // 0 or 1 element

    Node * left = head, * right = head->next, * nextR = head->next->next;  

    left->next = NULL;

    while(right){

        right->next = left;

        left = right;
        right = nextR;
        if(nextR) nextR = nextR->next;
    }

    return left;
}


void PrintLL(Node * head){
    Node* t = head;

    while(t){
        cout<<t->val<<"-> ";
        t= t->next;
    }
    cout<<"\n";
}


int main(){

    Node* dummy = new Node(0);
    Node* cur = dummy;
    for(int i=0; i<=10; i++){
        cur->next = new Node(abs(i-5));
        cur = cur->next;
    }


    cout<<" Before : ";
    PrintLL(dummy->next);



    Node* middle = split(dummy->next);
    Node* rev = reverse(middle); 
    
    Node * t1=dummy->next, *t2 = rev;
    while(t1 && t2){
        cout<<" - "<<t1->val<<" "<<t2->val<<"\n";
        if(t1->val != t2->val){
            cout<<" not palindrome\n";
            return 0;
        }

        t1=t1->next;
        t2=t2->next;
    }

    cout<<"palindrom\n";

    cout<<" after : ";
    PrintLL(rev);

    return 0;
}
