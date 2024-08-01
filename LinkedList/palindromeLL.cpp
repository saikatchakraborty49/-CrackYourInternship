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
    ListNode* reverse(ListNode* head){
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr!=NULL){
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    ListNode* findMid(ListNode* head){
        ListNode* fast=head->next;
        ListNode* slow=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
public:
    bool isPalindrome(ListNode* head) {
        ListNode* mid=findMid(head);
        mid->next=reverse(mid->next);
        ListNode* temp=head;
        ListNode* tempAfterMid=mid->next;
        while(temp!=mid->next && tempAfterMid!=NULL){
            if(temp->val!=tempAfterMid->val){
                return false;
            }
            temp=temp->next;
            tempAfterMid=tempAfterMid->next;
        }
        return true;
    }
};