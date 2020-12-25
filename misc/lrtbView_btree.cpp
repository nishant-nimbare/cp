#include <bits/stdc++.h>

#define PS <<" - "<<
#define PG <<"  "<<
#define PE <<endl

using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int v) : val(v){}
};

Node * root = nullptr;

void printBT(const std::string& prefix, const Node * node, bool isLeft)
{
    if( node != nullptr ){
        std::cout << prefix;
        std::cout << (isLeft ? "├──" : "└──" );
        // print the value of the node
        std::cout << node->val << std::endl;
        // enter the next tree level - left and right branch
        printBT( prefix + (isLeft ? "│   " : "    "), node->left, true);
        printBT( prefix + (isLeft ? "│   " : "    "), node->right, false);
    }
}


// preorder dfs
void leftView(Node * n, int &heightSeen, int curHeight){
    
    if(!n) return;

    if(curHeight > heightSeen){
        cout<<n->val<<"  ";
        heightSeen = curHeight;
    }

    leftView(n->left, heightSeen, curHeight + 1);
    leftView(n->right, heightSeen, curHeight + 1);

}

// preorder reverse dfs (process right before left)
void rightView(Node * n, int &heightSeen, int curHeight){
    
    if(!n) return;

    if(curHeight > heightSeen){
        cout<<n->val<<"  ";
        heightSeen = curHeight;
    }

    rightView(n->right, heightSeen, curHeight + 1);
    rightView(n->left,  heightSeen, curHeight + 1);

}


// can be done with lvl order traveral + map< left/right dist , val> (bfs)
//
// passing height and horizontal distance in recursion  (dfs) map < left/right dist, pair< val , height> >

void topView(Node * n, int horizontal, int height, map<int, pair<int, int> > &mmap){

    if(!n) return;

    if(mmap.count(horizontal) == 0){ 
        mmap[horizontal] = make_pair(n->val, height);
    }else{
        if(mmap[horizontal].second > height ){
            mmap[horizontal] = make_pair(n->val, height);
        }
    }

    topView(n->left, horizontal-1, height+1, mmap);
    topView(n->right, horizontal+1, height+1, mmap);

}

void bottomView(Node * n, int horizontal, int height, map<int, pair<int, int> > &mmap){

    if(!n) return;

    if(mmap.count(horizontal) == 0){ 
        mmap[horizontal] = make_pair(n->val, height);
    }else{
        if(mmap[horizontal].second < height ){
            mmap[horizontal] = make_pair(n->val, height);
        }
    }

    bottomView(n->left, horizontal-1, height+1, mmap);
    bottomView(n->right, horizontal+1, height+1, mmap);

}


int main(){
    root = new Node(20); 
    root->left = new Node(8); 
    root->right = new Node(22); 
    root->left->left = new Node(5); 
    root->left->right = new Node(3); 
    root->right->left = new Node(4); 
    root->right->right = new Node(25); 
    root->left->right->left = new Node(10); 
    root->left->right->right = new Node(24); 
    root->left->right->right->right = new Node(11);
    root->left->right->right->right->right = new Node(12);
    root->left->right->right->right->right->left = new Node(13);
    root->left->right->right->right->right->left->left = new Node(14);
    root->left->right->right->right->right->left->left->left = new Node(15);
    root->left->right->right->right->right->left->left->left->left = new Node(16);
    root->left->right->right->right->right->left->left->left->left->left = new Node(17);
    root->left->right->right->right->right->left->left->left->left->left->left = new Node(18);
    printBT("",root, false);


    cout PE <<" -------------- LEFT VIEW ----------- " PE ;
    int height = -1;
    leftView(root, height, 0);


    cout PE <<" -------------- RIGHT VIEW ----------- " PE ;
    height = -1;
    rightView(root, height, 0);


    cout PE <<" -------------- TOP VIEW ----------- " PE ;
    map<int, pair<int, int> > topmap;
    topView(root, 0, 0, topmap);
    for(auto ele : topmap) cout<<ele.second.first<<"  ";

    cout PE <<" -------------- BOTTOM VIEW ----------- " PE ;
    map<int, pair<int, int> > btmmap;
    bottomView(root, 0, 0, btmmap);
    for(auto ele : btmmap) cout<<ele.second.first<<"  ";


    return 0;
}