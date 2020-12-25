#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int val=0;
    struct Node* next;
    Node (int v) : val(v), next(NULL) {}
};

void printLL(Node * t){
    while(t) cout<<t->val<<" ", t=t->next;
    cout<<endl;
}


Node * traverseSimul(Node* h1, Node* h2, int diff){

    while(diff--){
        h1 = h1->next;
    }

    while(h1!=h2){
        h1=h1->next;
        h2=h2->next;
    }

    return h1;
}

Node * findIntersection(Node* h1, Node* h2){

    //count both length

    int l1=0, l2=0;

    Node * t = h1;
    while(t){
        l1++;
        t=t->next;
    }

    t = h2;
    while(t){
        l2++;
        t=t->next;
    }


    if(l1>l2){
        return traverseSimul(h1, h2, l1-l2);
    }else{
        return traverseSimul(h2, h1, l2-l1);
    }


}


int main(){

    srand(time(NULL));

    int s1= rand()%10 +1, s2 = rand() %5 + 1;

    Node * h1 = new Node(rand()%100);
    Node * prev = h1;
    for(int i=0; i<s1; i++){

        Node * new_node = new Node(rand()%100);
        prev->next = new_node;
        prev = new_node;
    }

    Node * h2 = new Node(rand()%100);
    prev = h2;
    for(int i=0; i<s2; i++){

        Node * new_node = new Node(rand()%100);
        prev->next = new_node;
        prev = new_node;
    }


    int intersection = rand()%s1 + 1;

    Node * t = h1;
    while(intersection--){
        t = t->next;
    }

    prev->next = t;

    printLL(h1);
    printLL(h2);

    cout<<" ANS : "<<endl;
    cout<<findIntersection(h1,h2)->val<<endl;

}