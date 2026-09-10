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
    ListNode* ans = nullptr;
    void fn(ListNode* head, ListNode* prev){
        if(!head->next){
            head->next = prev;
            ans = head;
            return;
        }
        fn(head->next, head);
        head->next = prev;
    }
    ListNode* reverseList(ListNode* head) {
        if(!head) return head;
        // ListNode* prev = nullptr;
        // ListNode* cur = head;
        // ListNode* next = head->next;

        // while(cur != nullptr){
        //     cur->next = prev;
            
        //     prev = cur;
        //     cur = next;
        //     if(next) next = next->next;
        // }

        // return prev;

        ListNode* temp = head;
        fn(temp, nullptr);

        return ans;
    }
};