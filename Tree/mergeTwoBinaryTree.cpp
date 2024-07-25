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
    // TreeNode* solve(TreeNode* root1,TreeNode* root2){
    //     if(root1==NULL and root2==NULL) return NULL;
    //     int left=0;
    //     int right=0;
    //     TreeNode* ans=new TreeNode(-1);
    //     if(root1!=NULL) left=root1->val;
    //     if(root2!=NULL) right=root2->val;
    //     ans->val=left+right;
    //     if(root2==NULL){
    //         ans->left=solve(root1->left,NULL);
    //         ans->right=solve(root1->right,NULL);
    //     }
    //     else if(root1==NULL){
    //         ans->left=solve(NULL,root2->left);
    //         ans->right=solve(NULL,root2->right);
    //     }
    //     else{
    //         ans->left=solve(root1->left,root2->left);
    //         ans->right=solve(root1->right,root2->right);
    //     }
    //     return ans;
    // }
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        // return solve(root1,root2);
        if(!root1) return root2;
        if(!root2) return root1;
        root1->val=root1->val+root2->val;
        root1->left=mergeTrees(root1->left,root2->left);
        root1->right=mergeTrees(root1->right,root2->right);
        return root1;
    }
};