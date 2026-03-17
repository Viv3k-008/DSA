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
    int ans = 0;
    pair<int,int> fn(TreeNode* root){
        if(root == NULL) return {0,INT_MIN};

        pair<int,int> left = fn(root->left);
        pair<int,int> right = fn(root->right);

        int op1 = (root->val == left.second)? left.first+1 : 0;
        int op2 = (root->val == right.second)? right.first+1 : 0;
        int op3 = (root->val == left.second && root->val == right.second)? left.first+right.first+2 : 0;

        ans = max({op1 , op2 , op3 , ans});

        return {max(op1 , op2) , root->val};
    }
    int longestUnivaluePath(TreeNode* root) {
        fn(root);

        return ans;
    }
};