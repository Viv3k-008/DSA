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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans(2,-1);

        ListNode* temp = head;
        ListNode* prev = NULL;

        ans[0] = 1e9, ans[1] = -1e9;
        int maxCnt = -1, minCnt = -1;
        while(temp){
            if(prev && temp->next && (prev->val > temp->val && temp->next->val > temp->val || prev->val < temp->val && temp->next->val < temp->val)){
                if(maxCnt == -1){
                    maxCnt = 0;
                }
                if(minCnt == -1){
                    minCnt = 1e9;
                }
                ans[1] = max(ans[1], maxCnt);
                ans[0] = min(ans[0], minCnt);
                minCnt = 0;
            }
            prev = temp;
            temp = temp->next;
            if(minCnt != -1) minCnt++;
            if(maxCnt != -1) maxCnt++;
        }
        if(ans[0] == 1e9 || ans[1] == -1e9) ans = {-1,-1}; 
        return ans;
    }
};