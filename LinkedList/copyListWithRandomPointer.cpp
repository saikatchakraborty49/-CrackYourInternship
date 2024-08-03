/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* helper(Node* head,unordered_map<Node*,Node*>&mpp){
        if(head==NULL) return NULL;
        Node* ele=new Node(head->val);
        mpp[head]=ele;
        ele->next=helper(head->next,mpp);
        ele->random=mpp[head->random];
        return ele;
    }
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*>mpp;
        return helper(head,mpp);
    }
};