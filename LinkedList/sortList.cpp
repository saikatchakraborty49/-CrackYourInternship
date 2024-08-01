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
    ListNode* merge(ListNode* a,ListNode* b){
        ListNode* ans=new ListNode(-1);
        ListNode* temp=ans;
        ListNode* tempA=a;
        ListNode* tempB=b;
        while(tempA!=NULL and tempB!=NULL){
            if(tempA->val<tempB->val){
                temp->next=tempA;
                tempA=tempA->next;
            }
            else{
                temp->next=tempB;
                tempB=tempB->next;
            }
            temp=temp->next;
        }
        if(tempA!=NULL){
            temp->next=tempA;
        }
        if(tempB!=NULL){
            temp->next=tempB;
        }
        return ans->next;
    }
   ListNode* findMid(ListNode* head) {
        if (head==NULL || head->next==NULL) return head;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next!=NULL && fast->next->next!=NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* mergeSort(ListNode* head){
        if(head==NULL || head->next==NULL) return head;
        ListNode* mid=findMid(head);
        ListNode* midNext=mid->next;
        mid->next=NULL;

        ListNode* left=mergeSort(head);
        ListNode* right=mergeSort(midNext);
        return merge(left,right);
    }

public:
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};