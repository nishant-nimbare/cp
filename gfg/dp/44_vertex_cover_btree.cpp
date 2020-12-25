#include <bits/stdc++.h>

#define DEBUG true

#ifdef DEBUG
#define dout cout
#else
#define dout 0 && cout
#endif

#define PS <<" - "<<
#define PG <<"  "<<
#define PE <<endl

using namespace std;

struct Node {
    int val;
    Node * left, *right;
    Node(int v) : val(v) {}
};


unordered_map<Node *, int> dp;

int vertexCover(Node * root){

    if(!root) return 0;
    if(!root->left && !root->right) return 0;

    if(dp.count(root) == 0 ){

        // 2 choices 
        // take current node 
        
        int c1 = 1 + vertexCover(root->left) + vertexCover(root->right);


        // dont take current,but then we have to take all children

        int c2 =0;

        if(root->left) 
            c2 += 1 + vertexCover(root->left->left) + vertexCover(root->left->right);


        if(root->right) 
            c2 += 1 + vertexCover(root->right->left) + vertexCover(root->right->right);


        dp[root] = min(c1, c2);
    }

    return dp[root];
}


int main(){

    Node *root                = new Node(20); 
    root->left                = new Node(8); 
    root->left->left          = new Node(4); 
    root->left->right         = new Node(12); 
    root->left->right->left   = new Node(10); 
    root->left->right->right  = new Node(14); 
    root->right               = new Node(22); 
    root->right->right        = new Node(25); 

    cout<<vertexCover(root)<<endl;

    return 0;

}