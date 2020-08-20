#include <iostream>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int v) : val(v){}
};

Node * root = nullptr;

void PrintTree(string prefix, Node * n){

    if(!n) return;

    cout<<prefix<<"└──"<<n->val<<endl;

    PrintTree(prefix+"  ", n->right);
    PrintTree(prefix+"  ", n->left);

}

void insert(int val, Node * n){

    if( root == nullptr ){
        root = new Node(val);
        return;
    } 


    if( val < n->val ){
        if(n->left) insert(val, n->left);
        else{
            n->left = new Node(val);
        }
    }else{
        if(n->right) insert(val, n->right);
        else{
            n->right = new Node(val);
        }
    }
}

Node* search(int val, Node *n){

    if(n==nullptr || n->val == val ) return n;
    
    if(val < n->val) return search(val, n->left);
    
    return search(val, n->right);
}

int main(){
    int t=10;

    srand(time(NULL));
    
    while(t--){
        insert(rand()%50, root);
    }

    PrintTree("", root);
    return 0; 
}