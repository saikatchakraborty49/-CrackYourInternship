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
    long long maxNode(TreeNode* root){
        if(root==NULL) return -1e10;
        long long ans1=maxNode(root->left);
        long long ans2=maxNode(root->right);
        if(root->val>ans1){
            if(root->val>ans2) return root->val;
            else return ans2;
        }
        else{
            if(ans1>ans2) return ans1;
            else return ans2;
        }
    }
    long long minNode(TreeNode* root){
        if(root==NULL) return 1e10;
        long long ans1=minNode(root->left);
        long long ans2=minNode(root->right);
        if(root->val<ans1){
            if(root->val<ans2) return root->val;
            else return ans2;
        }
        else{
            if(ans1<ans2) return ans1;
            else return ans2;
        }
    }
public:
    bool isValidBST(TreeNode* root) {
        if(root==NULL) return true;
        bool ans1=(root->val)>(maxNode(root->left)) && (root->val)<(minNode(root->right));
        bool ans2=isValidBST(root->left);
        bool ans3=isValidBST(root->right);
        return ans1 && ans2 && ans3;
    }
};