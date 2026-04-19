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
    void fn(TreeNode* root , TreeNode* p , TreeNode* q , TreeNode*& lca){
        if(!root) return;

        if(root->val < p->val){
            fn(root->right , p , q , lca);
        }
        else if(root->val > q->val){
            fn(root->left , p , q , lca);
        }
        else lca = root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* temp = NULL;

        if(p->val > q->val){
            temp = p;
            p = q;
            q = temp;
        }

        TreeNode* lca = NULL;
        fn(root , p , q , lca);

        return lca;
    }
};