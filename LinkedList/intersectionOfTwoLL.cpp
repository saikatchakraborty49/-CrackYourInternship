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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempA=headA;
        ListNode* tempB=headB;
        while(tempA!=NULL){
            tempA->val*=-1;
            tempA=tempA->next;
        }
        ListNode* ans;
        while(tempB!=NULL){
            if(tempB->val<0){
                ans=tempB;
                break;
            }
            tempB=tempB->next;
        }
        tempA=headA;
        //for maintaining the structure sabko vapas -1 se multiply karo
        while(tempA!=NULL){
            tempA->val*=-1;
            tempA=tempA->next;
        }
        return ans;
    }
};