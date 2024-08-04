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
private:
    ListNode* findMid(ListNode* head){
        ListNode* fast=head;
        ListNode* slow=head;
        ListNode* prev=NULL;
        while(fast!=NULL and fast->next!=NULL){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        return prev;
    }
    ListNode* reverse(ListNode* node){
        ListNode* curr=node;
        ListNode* prev=NULL;
        while(curr!=NULL){
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
public:
    void reorderList(ListNode* head) {
        if(head->next==NULL) return ;
        ListNode* beforeMid=findMid(head);
        ListNode* mid=beforeMid->next;;
        beforeMid->next=NULL;
        mid=reverse(mid);
        ListNode* firstNode=head;
        ListNode* secondNode=head->next;
        ListNode* lastNode=mid;
        ListNode* secondLastNode=mid->next;
        while(secondNode!=NULL){
            firstNode->next=lastNode;
            lastNode->next=secondNode;
            firstNode=secondNode;
            secondNode=secondNode->next;
            lastNode=secondLastNode;
            secondLastNode=secondLastNode->next;
        }
        firstNode->next=lastNode;
    }
};