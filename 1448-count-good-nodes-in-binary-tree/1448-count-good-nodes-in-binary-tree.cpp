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
    void fn(TreeNode* root , int maxi , int& cnt){
        if(!root) return;

        if(root->val >= maxi) cnt++;
        maxi = max(maxi , root->val);

        fn(root->left , maxi , cnt);
        fn(root->right , maxi , cnt);
    }
    int goodNodes(TreeNode* root) {
        int cnt = 0;
        fn(root , INT_MIN , cnt);

        return cnt;
    }
};