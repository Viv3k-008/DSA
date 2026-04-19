/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";

        queue<TreeNode*> q;
        q.push(root);

        string s = "";
        while(!q.empty()){
            int size = q.size();
            
            for(int i = 0 ; i < size ; i++){
                TreeNode* nd = q.front();
                q.pop();

                if(!nd) s += "#,";
                else s += to_string(nd->val) + ',';

                if(nd){
                    q.push(nd->left);
                    q.push(nd->right);
                }
            }
        }

        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
       if(data.size() == 0) return NULL;

       queue<TreeNode*> q;

       vector<string> nums;
       string temp = "";
       for(int i = 0 ; i < data.size() ; i++){
          if(data[i] != ',') temp += data[i];
          else {
            nums.push_back(temp);
            temp = "";
          }
       }

       TreeNode* root = new TreeNode(stoi(nums[0]));
       q.push(root);
       int idx = 1;

       while(!q.empty()){
           TreeNode* top = q.front();
           q.pop();

           if(nums[idx] != "#"){
              TreeNode* leftNd = new TreeNode(stoi(nums[idx++]));
              top->left = leftNd;
           }
           else {
              top->left = NULL;
              idx++;
           }

           if(nums[idx] != "#"){
              TreeNode* rightNd = new TreeNode(stoi(nums[idx++]));
              top->right = rightNd;
           }
           else {
              top->right = NULL;
              idx++;
           }
           

           if(top->left) q.push(top->left);
           if(top->right) q.push(top->right);
       }

       return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));