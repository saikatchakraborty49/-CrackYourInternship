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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* start=head;
        int kCopy=k;
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* temp=curr;
        ListNode* next=head->next;
        while(kCopy!=0){
            if(temp==NULL) return start;
            temp=temp->next;
            kCopy--;
        }
        kCopy=k;
        while(kCopy!=0){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            kCopy--;
        }
        // if(next==NULL) cout<<"null hai bhai";
        // cout<<next->val;
        start->next=reverseKGroup(next,k);
        return prev;
    }
};