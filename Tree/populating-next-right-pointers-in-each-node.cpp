/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL) return root;
        queue<Node*>q;
        q.push(root);
        q.push(NULL);
        while(q.size()>1){
            Node* front=q.front();
            Node* prev=front;
            while(q.front()!=NULL){
                if(front->left)
                q.push(front->left);
                if(front->right)
                q.push(front->right);
                q.pop();
                front=q.front();
                prev->next=front;
                prev=front;
            }
            if(q.front()==NULL){
                q.pop();
                q.push(NULL);
            }
        }
        return root;
    }
};