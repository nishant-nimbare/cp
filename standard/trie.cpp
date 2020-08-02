#include <bits/stdc++.h>

#define DEBUG true

#ifdef DEBUG
#define dout cout
#else
#define dout 0 && cout
#endif

using namespace std;


struct Node{

    char cur;
    unordered_map<char, Node*> children;
    bool end;
    size_t count = 0;
    Node(char c) : cur(c), end(false) {}

};


Node* dummy = new Node('-');



void insert(string word){

    Node * cur = dummy;

    for(char c : word){
        if(cur->children.count(c)==0){
            // insert child
            cur->children[c] = new Node(c);
        }
        cur = cur->children[c];
    }

    cur->end = true;
    cur->count+=1;

}


void printTree(string prefix, Node* head){

    if(!head) return;

    std::cout << prefix;

    std::cout << "└──" ;

    // print the value of the node
    cout << head->cur;
    
    if(head->end) cout<<" ("<<head->count<<") ";

    cout<< std::endl;

    // enter the next tree level - left and right branch

    unordered_map<char, Node*> :: iterator it = head->children.begin();

    for(; it != head->children.end(); it++){
        printTree( prefix + "   ",  it->second );    
    }

}


int main(){

    string cur;
    cin>>cur;
    while(cur != "exit"){
        insert(cur);
        cin>>cur;
    }

    cout<<" -------- \n";

    printTree(" ",dummy);
}