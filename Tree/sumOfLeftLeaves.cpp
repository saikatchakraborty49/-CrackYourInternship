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
public:
    void f(TreeNode* root,int &sum){
        if(root==NULL){
            sum+=0;
            return ;
        }
        //Leaf Node
        if(root->left!=NULL and root->left->left==NULL and root->left->right==NULL){
            sum+=root->left->val;
        };
        f(root->left,sum);
        f(root->right,sum);
    }
// public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum=0;
        f(root,sum);
        return sum;
    }
};