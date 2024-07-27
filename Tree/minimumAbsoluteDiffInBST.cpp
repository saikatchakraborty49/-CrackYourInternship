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
    void getInorder(TreeNode* root,TreeNode* &prev,int &diff){
        if(root==NULL) return ;
        getInorder(root->left,prev,diff);
        if(prev!=NULL){
            diff=min(diff,abs(prev->val-root->val));
        }
        prev=root;
        getInorder(root->right,prev,diff);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        int diff=INT_MAX;
        TreeNode* prev=NULL;
        getInorder(root,prev,diff);
        return diff;
    }
};