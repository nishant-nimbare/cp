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
    unordered_map<char, node*> children;
    bool end;

    Node(char c) : cur(c), end(false) {}

};


Node* dummy = new Node('-');

int