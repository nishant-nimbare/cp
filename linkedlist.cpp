#include <bits/stdc++.h>

using namespace std;

std::fstream myfile("./input.txt", std::ios_base::in);


struct Node
{
    int data=0;
    struct Node* next;
};


Node* result;

void printLink(Node* h){

	Node* t = h;

	cout<<" LL \n";
	while(t != NULL){
		cout<<t->data<<" ";
		t = t->next;
	}
	cout<<"\n\n";
}

Node* initailize(){

	Node* head = new Node();
	int n=0;
	myfile>>n;

	Node* tail = head;
	for (int i = 1; i < n; i++)
	{
		myfile>> (tail->data);
		Node* newnode = new Node();
		tail->next = newnode;
		tail= tail->next;
	}

	myfile>>(tail->data);	

	return head;
}

Node* getMiddle(Node* h, Node* e){

	Node* fast=h,* slow=h;

	while(fast->next->next != e) fast = fast->next->next, slow = slow->next; 

	return slow;
}


Node* merge(Node* h1, Node* h2){
	
	Node* resHead = NULL;
	Node* resTail = resHead;

	while( (h1 != NULL) && (h2 != NULL) ){
		
		Node* newnode = new Node();

		if(resHead == NULL){
			resHead = newnode;
			resTail = newnode;
		}
		
		if( h1->data <= h2->data ){
			
			newnode->data = h1->data;
			h1 = h1 -> next;
		}
		else{
			newnode->data = h2->data;
			h2 = h2 -> next;
		}

		resTail->next= newnode;

		resTail = resTail->next;
		
	}

	if(h1 != NULL) resTail->next = h1;
	if(h2 != NULL) resTail->next = h2;

	return resHead;
}


void mergeSort(Node* s, Node* m, Node* e){

	

}

void Divide(Node* s, Node* e){
//     0 elem  		1 elem
	if(s == e || s->next == e){
		return;
	}

	// 2 elem
	if(s->next->next == e){
		int a=s->data, b=s->data;
		s->data = min(a,b);
		s->next->data = max(a,b);
		return;
	}	


	Node* middle = getMiddle(s,e);

	Divide(s, middle);
	Divide(middle, e);


	mergeSort(s,middle,e);

}

void startMergeSort(Node* h){

	Node* res=NULL,*t=h, *rest=NULL;

	// res = rest;
	while(t != NULL){

		Node* newnode = new Node();
		// newnode->data=-1;

		if(res == NULL){
			res = newnode;
			rest = newnode;
		}else{
			rest->next = newnode;
			rest = rest->next;
		}

		t=t->next; 
	}

	printLink(h);
	printLink(res);

	::result = res;


	Divide(h,NULL);

}




int main(int argc, char const *argv[]){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	Node* head1 = initailize();
	// printLink(head1);

	startMergeSort(head1);

	// Node* head2 = initailize();
	// printLink(head2);


	// Node* res = merge(head1,head2);
	// printLink(res);

	return 0;
}