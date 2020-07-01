#include <bits/stdc++.h>
using namespace std;

struct  Node{
    int val;
    Node *left, *right;
    Node(){
        val = 0;
    }

    Node(int v){
        val = v;
    }
};


vector<Node *> recur(int k){

    if( k == 0 ) return vector<Node *>{nullptr};

    if( k == 1 ) return vector<Node *>{new Node(k)};

    vector<Node *> res;
    for(int i=1; i<k-1; i+=2){


        vector<Node *> lc = recur(i);
        vector<Node *> rc = recur(k-1-i);
    
        for(auto l : lc){
            for(auto r: rc){
                Node * current = new Node(k);
                current->left = l;
                current->right = r;
                res.push_back(current);
            }
        }
    }


    return res;
}


void print2d(Node * n, int space){

    if(!n) return;

    space+=2;

    print2d(n->right, space);

    cout<<endl;
    for(int i=0;i<space;i++) cout<<" ";
    cout<<n->val;

    print2d(n->left, space);
}

int main(){

    vector<Node *> all = recur(7);

    for(Node * n: all){

        cout<<"\n\n-----------------\n\n";
        print2d(n, 0);
    }


    return 0;

}
