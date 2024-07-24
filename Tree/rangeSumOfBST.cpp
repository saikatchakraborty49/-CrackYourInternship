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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root==NULL) return 0;
        int ans1=0;
        int ans2=0;
        if(root->val<=high and root->val>=low){
            ans1=root->val+rangeSumBST(root->left,low,high);
            ans2=rangeSumBST(root->right,low,high);
        }
        else if(root->val>high){
            ans1=rangeSumBST(root->left,low,high);
        }
        else if(root->val<low){
            ans2=rangeSumBST(root->right,low,high);
        }
        return ans1+ans2;
    }
};