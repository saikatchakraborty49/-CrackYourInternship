/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    bool f(TreeNode* p,TreeNode* q){
        if(p==NULL and q==NULL) return true;
        else if((p==NULL and q!=NULL) or (p!=NULL and q==NULL)) return false;
        if(p->val!=q->val) return false;

        int ans1=f(p->right,q->left);
        int ans2=f(p->left,q->right);
        return ans1 and ans2;
    }
public:
    bool isSymmetric(TreeNode* root) {
        return f(root->left,root->right);
    }
};