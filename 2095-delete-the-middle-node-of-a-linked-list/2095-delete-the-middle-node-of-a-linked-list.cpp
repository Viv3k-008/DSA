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
    ListNode* deleteMiddle(ListNode* head) {
        int n = 0;

        ListNode* temp = head;

        while(temp){
            n++;
            temp = temp->next;
        }
        if(n == 1) return NULL;

        n = n/2;
        n--;

        temp = head;
        ListNode* nextNode = head->next;

        while(n--){
            temp = temp->next;
            nextNode = nextNode->next;
        }

        temp->next = nextNode->next;

        return head;
    }
};