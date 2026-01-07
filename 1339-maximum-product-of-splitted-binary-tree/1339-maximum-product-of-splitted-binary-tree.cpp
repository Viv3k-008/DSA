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
    int mod = 1e9+7;
    long long totalSum = 0;
    void dfsForSum(TreeNode* root){
        if(root == NULL) return;

        totalSum += root->val;
        dfsForSum(root->left);
        dfsForSum(root->right);
    }
    long long maxi = 0;
    long long fn(TreeNode* root){
        if(root == NULL) return 0;

        long long left = fn(root->left);
        long long right = fn(root->right);
        
        long long subTreeSum = left + right + root->val;
        maxi = max(maxi , (totalSum - left) * left);
        maxi = max(maxi , (totalSum - right) * right);

        return subTreeSum;
    }
    int maxProduct(TreeNode* root) {
        dfsForSum(root);
        fn(root);

        return  maxi%mod;
    }
};