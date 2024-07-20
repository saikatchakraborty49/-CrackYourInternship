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
bool isSame(TreeNode* root, TreeNode* subRoot){
    if(root==NULL and subRoot==NULL) return true;
    if((root==NULL and subRoot!=NULL) or (root!=NULL and subRoot==NULL) or root->val!=subRoot->val) return false;
    
    bool ans1=isSame(root->left,subRoot->left);
    bool ans2=isSame(root->right,subRoot->right);

    return ans1 and ans2;
}
class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL) return false;
        if(root->val==subRoot->val){
            if(isSame(root,subRoot)) return true;
        }
        bool ans1=isSubtree(root->left,subRoot);
        bool ans2=isSubtree(root->right,subRoot);
        return ans1 or ans2;
    }
};