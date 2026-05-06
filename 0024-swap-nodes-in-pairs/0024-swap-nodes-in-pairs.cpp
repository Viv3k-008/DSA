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
    void Swap(ListNode* root){
        if(!root || !root->next) return;

        int val = root->val;
        root->val = root->next->val;
        root->next->val = val;

        Swap(root->next->next);
    }
    ListNode* swapPairs(ListNode* head) {
        if(!head) return NULL;

        Swap(head);

        return head;
    }
};