/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    int ans =0;
    
    int recur(TreeNode* n){
        
        if(!n) return 0;
        
        int lc = recur(n->left);
        int rc = recur(n->right);
        
        ans+= mod(lc) + mod(rc);
        
        return lc+rc+(n->val - 1 );

    }
    
    int distributeCoins(TreeNode* root) {
        ans = 0;
        recur(root);
        return ans;
    }
    
    
    int mod(int x){
        if(x<0) return (-(x));
        else return x;
    }
};