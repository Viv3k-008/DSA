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
    int cnt = 0;
    int fn(TreeNode* root){
        if(root == NULL){
            return INT_MIN; // -1e9
        }

        int left = fn(root->left);
        int right = fn(root->right);

        if(root->val >= max(left,right)){
            cnt++;
        }

        return max({root->val,left,right});
    }
    int countDominantNodes(TreeNode* root) {
        
        fn(root);

        return cnt;
    }
};