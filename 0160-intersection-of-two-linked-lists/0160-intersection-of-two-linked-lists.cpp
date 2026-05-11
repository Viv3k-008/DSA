/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int count(ListNode* root){
        int cnt = 0;

        while(root){
            cnt++;
            root = root->next;
        }

        return cnt;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1 = count(headA);
        int len2 = count(headB);

        while(len1 < len2){
            headB = headB->next;
            len2--;
        }
        while(len2 < len1){
            headA = headA->next;
            len1--;
        }

        while(headA != headB){
            headA = headA->next;
            headB = headB->next;
        }

        return headA;
    }
};