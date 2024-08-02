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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL) return NULL;
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
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1=reverseList(l1);
        ListNode* temp2=reverseList(l2);

        ListNode* ans=new ListNode(-1);
        ListNode* temp=ans;
        int carry=0;
        while(temp1!=NULL and temp2!=NULL){
            int val=temp1->val+temp2->val+carry;
            if(val>=10){
                val%=10;
                carry=1;
            }
            else{
                carry=0;
            }
            ListNode* ele=new ListNode(val);
            temp->next=ele;
            temp=temp->next;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        while(temp1!=NULL){
            int val=temp1->val+carry;
            if(val>=10){
                val%=10;
                carry=1;
            }
            else{
                carry=0;
            }
            ListNode* ele=new ListNode(val);
            temp->next=ele;
            temp=temp->next;
            temp1=temp1->next;
        }
        while(temp2!=NULL){
            int val=temp2->val+carry;
            if(val>=10){
                val%=10;
                carry=1;
            }
            else{
                carry=0;
            }
            ListNode* ele=new ListNode(val);
            temp->next=ele;
            temp=temp->next;
            temp2=temp2->next;
        }
        if(carry==1){
            ListNode* carryEle=new ListNode(1);
            temp->next=carryEle;
        }
        ans->next=reverseList(ans->next);
        return ans->next;
    }
};