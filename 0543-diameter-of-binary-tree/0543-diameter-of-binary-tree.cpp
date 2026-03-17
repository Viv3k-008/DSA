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
    int maxi = INT_MIN;
    int fn(TreeNode* root){
        if(root == NULL) return 0;

        int left = fn(root->left);
        int right = fn(root->right);

        maxi = max(left+right , maxi);

        return max(left , right)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        fn(root);

        return maxi;
    }
};