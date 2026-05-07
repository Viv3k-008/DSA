/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        int k = lists.size();

        vector<int> nums;

        for(int i = 0 ; i < k ; i++){
            ListNode* root = lists[i];

            while(root){
                if(root) nums.push_back(root->val);
                root = root->next;
            }
        }

        int n = nums.size();

        sort(nums.begin(),nums.end());

        int idx = 0;
        if(n == 0) return NULL;
        ListNode* head = new ListNode(nums[idx++]);
        ListNode* temp = head;
        while(idx < n){
            temp->next = new ListNode(nums[idx++]);
            temp = temp->next;
        }

        return head;
    }
};