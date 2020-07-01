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




vector<Node *> recur(int lb, int rb){

    if( lb > rb ) return vector<Node *>{nullptr};

    if( lb == rb ) return vector<Node *>{new Node(lb)};

    vector<Node *> res;
    for(int i=lb; i<=rb; i+=1){

        vector<Node *> lc = recur(lb, i-1);
        vector<Node *> rc = recur(i+1, rb);
    
        for(auto l : lc){
            for(auto r: rc){
                Node * current = new Node(i);
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

    vector<Node *> all = recur(1,3);

    for(Node * n: all){

        cout<<"\n\n-----------------\n\n";
        print2d(n, 0);
    }


    return 0;

}
