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
    void fn(TreeNode* root , TreeNode* p , TreeNode* q , TreeNode*& ans){
        if(root == NULL) return;

        if(root->val < p->val){
            fn(root->right , p , q , ans);
        }
        else if(root->val > q->val){
            fn(root->left , p , q , ans);
        }
        else ans = root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = root;
        if(p->val > q->val){
            TreeNode* temp = p;
            p = q;
            q = temp;
        }
        fn(root , p , q , ans);

        return ans;
    }
};