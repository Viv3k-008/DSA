/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    bool fn(TreeNode* root , TreeNode* p , TreeNode* q , TreeNode*& lca){
        if(!root) return false;

        bool op1 = fn(root->left , p , q , lca);
        bool op2 = fn(root->right , p , q , lca);

        if((root == p || root == q) && (op1 || op2)){
            lca = root;
        }
        else if(op1 && op2){
            lca = root;
        }

        if(root == p || root == q) return true;

        return op1 || op2;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* lca = NULL;

        fn(root , p , q , lca);

        return lca;
    }
};