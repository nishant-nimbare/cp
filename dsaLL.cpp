#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    struct node *next;

};


void initialize(node* head){
    node* ptr;
    head->data=0;
    ptr=head;

    for(int i=1; i<10; i++){
        node *nnode = new node();
        nnode->data = i;
        ptr->next = nnode;
        ptr = ptr->next;
    }

    node* p2=head;
    while( p2 != NULL ){ 
        cout<<p2->data<<" "; 
        p2=p2->next;
    }
    cout<<"\n";

    p2=head;
    while( p2->data != 4 ) p2=p2->next;

    ptr->next=p2;

    p2=head;
    for(int i=1; i<20; i++){
        cout<<p2->data<<" "; 
        p2=p2->next;
    }
    cout<<"\n";
}




int main(int argc, char const *argv[]){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    node *head;
    initialize(head);

    node *f=head, *s=head;

    int k=1; 

    // collision
    while(f!=s){
        s=s->next;
        f=f->next->next;
        k++;
    }
   
   // loop Length
   int loopLen = 1;
   f=f->next;

   while(f!=s) {
        f=f->next;
        loopLen++;
    }





	return 0;
}