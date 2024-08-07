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
    ListNode* partition(ListNode* head, int x) {
        ListNode* smallHead=new ListNode(-1);
        ListNode* bigHead=new ListNode(-1);
        ListNode* small=smallHead;
        ListNode* big=bigHead;
        ListNode* temp=head;
        while(temp!=NULL){
            if(temp->val<x){
                small->next=temp;
                small=small->next;
                temp=temp->next;
            }
            else{
                big->next=temp;
                big=big->next;
                temp=temp->next;
            }
        }
        small->next=bigHead->next;
        big->next=NULL;
        return smallHead->next;
    }
};