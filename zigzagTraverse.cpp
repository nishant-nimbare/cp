#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    vector<Node*> children;
    Node(int v):val(v) {}
};


vector<Node *> nextLvl(vector<Node *> stac1, bool dir){

    vector<Node *> stac2;

    while(stac1.size()){

        Node* cur = stac1.back();
        stac1.pop_back();

        cout<<cur->val<<" ";

        if(dir){
            for(int i=0; i<cur->children.size(); i++){
                stac2.push_back(cur->children[i]);
            }
        }else{
            for(int i=cur->children.size()-1; i>=0; i--){
                stac2.push_back(cur->children[i]);
            }
        }
    }

    return stac2;
}

void zigzag(Node* root){

    if(!root) return;

    vector<Node *> stac1;

    stac1.push_back(root);

    bool dir = true;

    while(stac1.size()){
        cout<<"\n";
        stac1 = nextLvl(stac1,dir);
        dir = !dir;
    }

}




int main(int argc, char const *argv[]){

    Node * root = new Node(1);

    // vector<vector<Node *>> temp;

    // for(int t=2; t<21; t++){
    //     vector<Node *>
    // }


    Node * c2 = new Node(2);
    Node * c3 = new Node(3);
    Node * c4 = new Node(4);
    Node * c5 = new Node(5);
    Node * c6 = new Node(6);
    Node * c7 = new Node(7);
    Node * c8 = new Node(8);
    Node * c9 = new Node(9);
    Node * c10 = new Node(10);
    Node * c11 = new Node(11);
    Node * c12 = new Node(12);
    Node * c13 = new Node(13);
    Node * c14 = new Node(14);
    Node * c15 = new Node(15);
    Node * c16 = new Node(16);


    root->children = vector<Node*> {c2,c3};
    c2->children = vector<Node*> {c4,c5};
    c3->children = vector<Node*> {c6,c7,c8};
    c4->children = vector<Node*> {c9,c10};
    c6->children = vector<Node*> {c11,c12,c13};
    c7->children = vector<Node*> {c14,c15};
    c8->children = vector<Node*> {c16};


    zigzag(root);   


}