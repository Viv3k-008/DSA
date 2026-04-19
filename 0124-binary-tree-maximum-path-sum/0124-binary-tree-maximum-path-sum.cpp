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
    int fn(TreeNode* root , int& maxi){
        if(!root) return 0;

        int left = fn(root->left , maxi);
        int right = fn(root->right , maxi);

        int op1 = left + root->val;
        int op2 = right + root->val;
        int op3 = root->val;
        int op4 = left + right + root->val;
        

        maxi = max({maxi , op1 , op2 , op3 , op4});

        return max({op1 , op2 , op3});
    }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        fn(root , maxi);

        return maxi;
    }
};