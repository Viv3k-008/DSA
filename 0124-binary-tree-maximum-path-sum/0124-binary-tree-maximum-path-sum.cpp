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

        int op1 = left + root->val;
        int op2 = right + root->val;
        int op3 = left + right + root->val;
        int op4 = root->val;

        maxi = max({maxi , op1 , op2 , op3 , op4});

        return max({op1 , op2 , op4});
    }
    int maxPathSum(TreeNode* root) {
        fn(root);

        return maxi;
    }
};