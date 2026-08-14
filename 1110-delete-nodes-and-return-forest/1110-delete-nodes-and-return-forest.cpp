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
    vector<TreeNode*> ans;
    TreeNode* fn(TreeNode* root, unordered_map<int,int>& mp){
        if(!root) return NULL;

        TreeNode* cur = new TreeNode(root->val);

        TreeNode* leftNd = fn(root->left, mp);
        TreeNode* rightNd = fn(root->right, mp);

        if(mp.count(cur->val)){
            if(leftNd) ans.push_back(leftNd);
            if(rightNd) ans.push_back(rightNd);
            return NULL;
        }
        cur->left = leftNd;
        cur->right = rightNd;
        return cur;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        int n = to_delete.size();
        unordered_map<int,int> mp;

        for(int i : to_delete) mp[i]++;

        TreeNode* cur = fn(root, mp);
        if(cur) ans.push_back(cur);

        return ans;
    }
};