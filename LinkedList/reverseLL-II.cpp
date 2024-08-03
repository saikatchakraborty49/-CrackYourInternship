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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int i=1;
        ListNode* temp=head;
        ListNode* prev=NULL;
        ListNode* leftNode=head;
        ListNode* rightNode=head;
        if(left==1){
            int i=1;
            ListNode* next=head->next;
            while(i<=right){
                next=temp->next;
                temp->next=prev;
                prev=temp;
                temp=next;
                i++;
            }
            head->next=temp;
            return prev;
        }

        ListNode* next=head->next;
        ListNode* firstLeft;
        ListNode* beforeLeft;
        while(temp!=NULL){
            if(i+1<left){
                i++;
                prev=temp;
                temp=temp->next;
                continue;
            }
            if(i+1==left){
                beforeLeft=temp;
                i++;
                prev=temp;
                temp=temp->next;
                continue;
            }
            if(i==left){
                firstLeft=temp;
                i++;
                prev=temp;
                temp=temp->next;
                continue;
            }
            if(i>right){
                break;
            }
            while(temp!=NULL and i>=left+1 and i<=right){
                next=temp->next;
                temp->next=prev;
                prev=temp;
                temp=next;
                i++;
            }
        }
        firstLeft->next=temp;
        beforeLeft->next=prev;
        return head;
    }
};