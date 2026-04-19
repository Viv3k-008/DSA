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
    unordered_map<TreeNode*,int> dp;
    void dfs(TreeNode* root){
        if(!root) return;

        dfs(root->left);
        dfs(root->right);

        int take = root->val;
        if(root->left) take += dp[root->left->left] + dp[root->left->right];
        if(root->right) take += dp[root->right->left] + dp[root->right->right];

        int notTake = 0;
        if(root->left) notTake += dp[root->left];
        if(root->right) notTake += dp[root->right];


        dp[root] = max(take , notTake);
    }
    int rob(TreeNode* root) {
        dfs(root);

        return dp[root];
    }
};