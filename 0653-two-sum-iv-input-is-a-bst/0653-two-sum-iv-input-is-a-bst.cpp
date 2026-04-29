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
    unordered_map<int,int> mp;
    bool ans = false;
    bool fn(TreeNode* root , int k){
        if(!root) return false;

        bool left = fn(root->left , k);
        if(mp.count(k-root->val)){
            return true;
        }
        mp[root->val]++;
        bool right = fn(root->right , k);

        return left || right;
    }
    bool findTarget(TreeNode* root, int k) {
        return fn(root , k);
    }
};