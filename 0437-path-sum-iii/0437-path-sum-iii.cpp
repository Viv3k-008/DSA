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
    unordered_map<long long,int> mp;
    void fn(TreeNode* root , int target , long long curSum){
        if(!root) return;

        curSum += root->val;
        if(mp.count(curSum-target)){
            cnt += mp[curSum-target];
        }

        mp[curSum]++;

        fn(root->left , target , curSum);
        fn(root->right , target , curSum);

        mp[curSum]--;
        if(mp[curSum] == 0){
            mp.erase(curSum);
        }
    }
    int pathSum(TreeNode* root, int targetSum) {
        mp[0] = 1;
        fn(root , targetSum , 0);
        return cnt;
    }
};