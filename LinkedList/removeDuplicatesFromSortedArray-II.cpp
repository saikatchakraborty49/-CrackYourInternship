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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL or head->next==NULL) return head;
        ListNode* ans=new ListNode(-1);
        ListNode* temp=ans;
        ListNode* curr=head;
        ListNode* next=head->next;
        while(curr!=NULL){
            if(next==NULL or (next!=NULL and curr->val!=next->val)){
                ListNode* ele=new ListNode(curr->val);
                temp->next=ele;
                temp=temp->next;
                curr=curr->next;
                if(next!=NULL)
                next=next->next;
            }
            else{
                while(next!=NULL and curr->val==next->val){
                    curr=next;
                    next=next->next;
                }
                if(next!=NULL){
                    curr=next;
                    next=next->next;
                }
                else if(next==NULL){
                    cout<<"idhar se return hua"<<endl;
                    return ans->next;
                }
            }
        }
        return ans->next;
    }
};