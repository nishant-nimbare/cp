#include<bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
                }

               return root;
           }
        }

/*
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/

    int dmax=0, dmin=0;
    unordered_map<int, pair<int,int> > mhash;

    void recur(Node* n, int hd, int lvl){
        if(!n) return;

        if( mhash.count(hd) == 0 ||  mhash[hd].second > lvl ){
            mhash[hd] = make_pair(n->data, lvl);
        }

        dmax = std::max(dmax, hd);
        dmin = std::min(dmin, hd);

        recur(n->left, hd-1, lvl+1);
        recur(n->right, hd+1, lvl+1);
    }

    void topView(Node * root) {

        if(!root) return;

        mhash.clear();
        dmax=0;
        dmin=0;
        
        recur(root, 0, 0);

        for(int k= dmin; k<= dmax; k++){
            cout<<mhash[k].first<<" ";
        }

    }

}; //End of Solution