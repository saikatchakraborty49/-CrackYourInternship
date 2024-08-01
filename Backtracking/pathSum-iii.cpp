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
    void solve(long long sum,int &ans,TreeNode* root, int targetSum,TreeNode* main,unordered_map<TreeNode*,bool>&mpp){
        if(root==NULL) return;
        if(sum+root->val==targetSum){
            ans+=1;
        }
        solve(sum+root->val,ans,root->left,targetSum,main,mpp);
        solve(sum+root->val,ans,root->right,targetSum,main,mpp);

        if(mpp[root]==false){
            mpp[root]=true;
            solve(0,ans,root->left,targetSum,main,mpp);
            solve(0,ans,root->right,targetSum,main,mpp);
        }
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        int ans=0;
        long long sum=0;
        unordered_map<TreeNode*,bool>mpp;
        solve(sum,ans,root,targetSum,root,mpp);
        return ans;
    }
};