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
        if(!root){
            return {0,0};
        }

        pair<int,int> left = fn(root->left);
        pair<int,int> right = fn(root->right);

        int totalSum = left.first+right.first+root->val;
        int totalCnt = left.second+right.second+1;

        int avg = ceil(totalSum/totalCnt);
        if(avg == root->val) ans++;

        return {totalSum, totalCnt};
    }
    int averageOfSubtree(TreeNode* root) {
        fn(root);
        return ans;
    }
};