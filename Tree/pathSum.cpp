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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return false;
        if(root->left==NULL and root->right==NULL and targetSum==root->val) return true;
        
        bool ans1=hasPathSum(root->left,(targetSum)-(root->val));
        bool ans2=hasPathSum(root->right,(targetSum)-(root->val));

        return (ans1 || ans2);
    }
};