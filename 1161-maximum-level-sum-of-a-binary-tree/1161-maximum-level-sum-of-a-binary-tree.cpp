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
    void fn(TreeNode* root , int lvl){
        if(root == NULL) return;


        fn(root->left , lvl+1);
        fn(root->right , lvl+1);
        mp[lvl] += root->val;
    }
    int maxLevelSum(TreeNode* root) {
        fn(root , 1);

        int maxi = INT_MIN , maxiLvl = -1;

        for(auto it : mp){
            if(it.second > maxi){
                maxi = it.second;
                maxiLvl = it.first;
            }
        }

        return maxiLvl;

    }
};