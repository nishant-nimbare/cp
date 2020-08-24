#include <iostream>
using namespace std;

/**
 * 
 * 4 cases : 
 * LL = right
 * LR = left , right
 * RR = left
 * RL = right , left
 * 
**/

enum rotationCase {
    LL, LR, RR, RL, none
};

struct Node {
    int val, leftHeight, rightHeight;
    Node *left, *right;
    Node(int v) : val(v){
        leftHeight = 0;
        rightHeight = 0;
    }
};

Node * root = nullptr;

void PrintTree(string prefix, Node * n){

    if(!n) return;

    cout<<prefix<<"└──"<<n->val<<" ("<<n->leftHeight<<","<<n->rightHeight<<")"<<endl;

    PrintTree(prefix+"  ", n->right);
    PrintTree(prefix+"  ", n->left);

}


int height(Node* x, bool left=false){
    if(left){ return (x) ? (x->leftHeight) : ( -1 );};

    return (x) ? (x->rightHeight) : ( -1 ) ;
}

rotationCase checkCase(Node * parent, int new_value){

    if( new_value <  parent->val  ){

        if(new_value < parent->left->val) return LL;

        return LR;

    }else{
        // parent->val < new_value
        if( parent->right->val < new_value) return RR;

        return RL;

    }

    return none;

}


Node * RotateLeft(Node* parent){
    
    /**
     *              p
     *       t              rc
     *                  rlgc     rrgc 
     * 
     *      ---------------------------
     *                  rc
     *        p                 rrgc
     *     t    rlgc
     * 
     * **/


    Node * rc = parent->right, * rlgc = rc->left;

    parent->right = rlgc;
    rc ->left = parent;


    parent->rightHeight =    max( height(parent->right, true), height(parent->right, false) ) + 1;
    rc->leftHeight      =    max( height(rc->left, true),      height(rc->left, false) ) + 1;


    // cout<<" changing heights "<<parent->rightHeight;
    return rc;
}



Node * RotateRight(Node* parent){
    
    /**
     *              p
     *       lc              rc
     *  llgc    lrgc         
     * 
     *      ---------------------------
     *                  lc
     *        llgc               p
     *                      lrgc    
     * 
     * **/


    Node * lc = parent->left, * lrgc = lc->right;

    parent->left= lrgc;
    lc ->right = parent;


    parent->leftHeight = max(height(parent->left, true), height( parent->left, false) ) + 1;
    lc->rightHeight =    max(height(lc->right, true), height( lc->right, false) ) + 1;


    // cout<<" changing heights "<<parent->rightHeight;
    return lc;
}




Node * insert(int val, Node * n){

    if( root == nullptr ){
        root = new Node(val);
        return root;
    } 


    if( val < n->val ){
        if(n->left) n->left = insert(val, n->left);
        else{
            n->left = new Node(val);
        }

        n->leftHeight += 1;
    }else{
        if(n->right) n->right =  insert(val, n->right);
        else{
            n->right = new Node(val);
        }
        n->rightHeight += 1;
    }


    

    // check for imbalances ( left height - rightHeight >1 or < -1)

    if( (n->leftHeight - n->rightHeight) > 1 || (n->leftHeight - n->rightHeight) < -1 ){

        // find where is the new inserted node wrt n and its child

        switch (checkCase(n, val))
        {
        case LL:
            return RotateRight(n);
            break;

        case RR:
            return RotateLeft(n);
            break;

        case LR:
            n->left = RotateLeft(n->left);
            return RotateRight(n);
            break;
        
        case RL:
            n->right = RotateRight(n->right);
            return RotateLeft(n);
            break;


        case none: cout<<" something went wrong\n"; break;
        default: cout<<" something went wrong\n"; break;

        }
    }

    return n;

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
        int new_value = rand()%50;
        // cin>>new_value;
        cout<<" - ----------------  inserting "<<new_value<<"\n";
        root = insert( new_value, root);
        PrintTree("", root);

    }

    return 0; 
}