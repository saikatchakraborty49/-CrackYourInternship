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
    void solve(ListNode* curr,ListNode* prev,int &n,ListNode* &ans){
        if(curr==NULL) return ;
        solve(curr->next,curr,n,ans);
        n--;
        if(n==0) {
            if(prev!=NULL)
            prev->next=curr->next;
            else {
                curr=curr->next;
            }
        }
        ans=curr;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* ans=head;
        solve(head,NULL,n,ans);
        return ans;
    }
};