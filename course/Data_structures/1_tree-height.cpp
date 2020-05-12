#include <algorithm>
#include <iostream>
#include <vector>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

class Node;

class Node {
public:
    int key;
    Node *parent;
    std::vector<Node *> children;

    Node() {
      this->parent = NULL;
    }

    void setParent(Node *theParent) {
      parent = theParent;
      parent->children.push_back(this);
    }
};


int height(Node* node){

  // std::cout<<" - traversing "<<node->key<<"\n";

  if(node == NULL) return 0;

  if(node->children.empty()) return 1;

  int subH = 0, ch=0;
  for(Node* c: node->children){
    ch=height(c);
    // std::cout<<ch<<" : cH of "<< c->key <<"\n";

    subH=(ch>subH)?(ch):(subH);
  }


  subH++;
  return (subH);
}

int main_with_large_stack_space() {
  std::ios_base::sync_with_stdio(0);
  int n;
  std::cin >> n;

  std::vector<Node> nodes;
  nodes.resize(n);
  int root;
  for (int child_index = 0; child_index < n; child_index++) {
    int parent_index;
    std::cin >> parent_index;

    nodes[child_index].key = child_index;

    if (parent_index >= 0)
      nodes[child_index].setParent(&nodes[parent_index]);
    else 
      root = child_index;
  
  }
  // std::cout<<root<<" : root\n";

  // Replace this code with a faster implementation
  // int maxHeight = 0;
  // for (int leaf_index = 0; leaf_index < n; leaf_index++) {
  //   int height = 0;
  //   for (Node *v = &nodes[leaf_index]; v != NULL; v = v->parent)
  //     height++;
  //   maxHeight = std::max(maxHeight, height);
  // }
    
  std::cout << height(&nodes[root]) << std::endl;
  return 0;
}

int main (int argc, char **argv)
{
#if defined(__unix__) || defined(__APPLE__)
  // Allow larger stack space
  const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0)
  {
      if (rl.rlim_cur < kStackSize)
      {
          rl.rlim_cur = kStackSize;
          result = setrlimit(RLIMIT_STACK, &rl);
          if (result != 0)
          {
              std::cerr << "setrlimit returned result = " << result << std::endl;
          }
      }
  }

#endif
  return main_with_large_stack_space();
}
