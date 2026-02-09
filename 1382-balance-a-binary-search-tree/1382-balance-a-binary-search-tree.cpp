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
    void dfs1(TreeNode* root , vector<int>& pre){
        if(root == NULL) return;

        dfs1(root->left , pre);
        pre.push_back(root->val);
        dfs1(root->right , pre);
    }
    TreeNode* dfs2(vector<int>& pre , int left , int right){
        if(left > right) return NULL;

        int mid = left + (right-left)/2;
        TreeNode* root = new TreeNode(pre[mid]);

        root->left = dfs2(pre , left , mid-1);
        root->right = dfs2(pre , mid+1 , right);

        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> pre;
        dfs1(root , pre);
        int i = 0;

        return dfs2(pre , 0 , pre.size()-1);
    }
};