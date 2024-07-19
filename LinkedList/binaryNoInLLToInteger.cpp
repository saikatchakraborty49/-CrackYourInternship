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
    void f(ListNode* root,int &power,int &ans){
        if(root==NULL) return ;
        f(root->next,power,ans);
        if(root->val==1)
        ans+=pow(2,power);
        power++;
    }
public:
    int getDecimalValue(ListNode* head) {
        int power=0;
        ListNode* temp=head;
        int ans=0;
        f(temp,power,ans);
        return ans;
    }
};