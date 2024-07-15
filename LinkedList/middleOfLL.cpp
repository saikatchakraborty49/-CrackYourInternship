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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow=head;
        if(head->next==NULL) return head;
        ListNode* fast=head->next;
        while(true){
            slow=slow->next;
            if(fast->next!=NULL and fast->next->next!=NULL) fast=fast->next->next;
            else return slow;
        }
        return head;
    }
};