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
    TreeNode* rec(int &index,int postStart,int postEnd,vector<int>& preorder, vector<int>& postorder){
        if(postStart>postEnd){
            index--;
            return NULL;
        }
        TreeNode* root=new TreeNode(preorder[index]);
        if(postStart==postEnd) return root;
        int i=0;
        while(preorder[index+1]!=postorder[i])i++;
        index+=1;
        root->left=rec(index,postStart,i,preorder,postorder);
        index+=1;
        root->right=rec(index,i+1,postEnd-1,preorder,postorder);
        return root;
    }
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int index=0;
        int postStart=0;
        int postEnd=postorder.size()-1;
        return rec(index,postStart,postEnd,preorder,postorder);
    }
};