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
    unordered_map<TreeNode*,int> mp;
    void fn(TreeNode* root){
        if(root == NULL) return;

        fn(root->left);
        fn(root->right);

        int take = root->val;
        if(root->left){
            if(root->left->left) take += mp[root->left->left];
            if(root->left->right) take += mp[root->left->right];
        }
        if(root->right){
            if(root->right->left) take += mp[root->right->left];
            if(root->right->right) take += mp[root->right->right];
        }

        int notTake = 0;
        if(root->left) notTake += mp[root->left];
        if(root->right) notTake += mp[root->right];

        mp[root] = max(take,notTake);
    }
    int rob(TreeNode* root) {
        if(!root) return 0;
        fn(root);

        return mp[root];
    }
};