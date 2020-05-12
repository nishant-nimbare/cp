#include <iostream>
#include <vector>
#include <algorithm>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif


using std::cin;
using std::cout;
using std::endl;
using std::vector;
using namespace std;

bool logs=false;
template <typename T>
void mlog(string txt, T val){
	if(logs) cout<<txt<<" "<<val<<"\t";
}


struct Node {
  int key;
  int left;
  int right;

  Node() : key(0), left(-1), right(-1) {}
  Node(int key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};

bool notBst = false;

int ino(const vector<Node>& tree, int i, int& maxL){

  
  if(tree[i].left==-1 && tree[i].right==-1) {
    
    if(tree[i].key < maxL) {
     notBst = true;
      return -2 ;
    }

    return tree[i].key;
  }
  
  if(tree[i].left!=-1) {
    int LChildMax = ino(tree, tree[i].left, maxL); 
    if(LChildMax==-2 || LChildMax>=tree[i].key) {
      notBst=true;
      return -2;
    }
  }


  if(tree[i].key < maxL) {
    notBst = true;
    return -2 ;
  }

  mlog<int>(" - key ",tree[i].key);
  mlog<int>(" - maxL ",maxL);
  mlog<char>(" ",'\n');

  maxL=tree[i].key;

  if(tree[i].right != -1)
  return ino(tree, tree[i].right, maxL);

  return maxL;
}

bool IsBinarySearchTree(const vector<Node>& tree) {
  // Implement correct algorithm here
  if(tree.size() <= 1 ) return true;

  int maxL = INT32_MIN;
  int m = ino(tree, 0, maxL);


  return (!notBst);
}

int main_with_large_stack_space() {
  int nodes;
  cin >> nodes;
  vector<Node> tree;
  for (int i = 0; i < nodes; ++i) {
    int key, left, right;
    cin >> key >> left >> right;
    tree.push_back(Node(key, left, right));
  }
  if (IsBinarySearchTree(tree)) {
    cout << "CORRECT" << endl;
  } else {
    cout << "INCORRECT" << endl;
  }
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

