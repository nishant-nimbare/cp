#include <bits/stdc++.h>

#define DEBUG true

#ifdef DEBUG
#define dout cout
#else
#define dout 0 && cout
#endif

using namespace std;


struct Node{

    int val;
    Node * next;

    Node(int v): val(v), next(nullptr) {}
};

int main(){
    int n = 10;
    Node * dummy = new Node(-1), * itr=dummy;

    srand(time(NULL));

    while(n--){
        Node * new_node = new Node(rand()%10 + 1);

        cout<<new_node->val<<" ";
        itr->next = new_node;

        itr = itr->next;
    }

    cout<<endl;
    cout<<"enter x : ";

    int x;
    cin>>x;

    itr = dummy->next;
    Node * last_seen = nullptr;

    while(itr){
        if(itr->val == x) last_seen = itr;
        itr = itr->next;
    }

    if(last_seen){
        if(! last_seen->next){
            //last ele of ll
            delete last_seen;
        }
        else{

            last_seen->val = last_seen->next->val;
            last_seen->next = last_seen->next->next;
            // delete last_seen->next;
        }
    
    }


    cout<<" Answer : "<<endl;

    itr = dummy->next;
    while(itr){
        cout<<itr->val<<" ";
        itr = itr->next;
    }


}
