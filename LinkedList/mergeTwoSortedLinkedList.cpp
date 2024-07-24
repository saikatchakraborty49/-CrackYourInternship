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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans=new ListNode(-1);
        ListNode* list1head=list1;
        ListNode* list2head=list2;
        ListNode* ansHead=ans;
        while(list1head!=NULL and list2head!=NULL){
            if(list1head->val<list2head->val){
                ans->next=list1head;
                list1head=list1head->next;
            }
            else{
                ans->next=list2head;
                list2head=list2head->next;
            }
            ans=ans->next;
        }
        if(list1head!=NULL){
            ans->next=list1head;
        }
        else if(list2head!=NULL){
            ans->next=list2head;
        }
        return ansHead->next;
    }
};