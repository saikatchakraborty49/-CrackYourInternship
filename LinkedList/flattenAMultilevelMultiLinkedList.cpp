/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
private:
    void dfs(Node* head,vector<int>&ans){
        if(head==NULL) return ;
        ans.push_back(head->val);
        if(head->child) dfs(head->child,ans);
        if(head->next) dfs(head->next,ans);
    }
public:
    Node* flatten(Node* head) {
        vector<int>nodes;
        dfs(head,nodes);
        Node* ans=new Node(-1);
        Node* temp=ans;
        for(int i=0;i<nodes.size();i++){
            Node* ele=new Node(nodes[i]);
            temp->next=ele;
            ele->prev=temp;
            ele->child=NULL;
            temp=temp->next;
        }
        if(ans->next!=NULL){
            ans->next->prev=NULL;
        }
        return ans->next;
    }
};