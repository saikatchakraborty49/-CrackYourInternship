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
    void solve(vector<int>&ans,unordered_map<int,bool>&mpp,TreeNode* root,int level){
        if(root==NULL) return;
        if(mpp[level]==false){
            ans.push_back(root->val);
            mpp[level]=true;
        }
        //right
        solve(ans,mpp,root->right,level+1);
        //left
        solve(ans,mpp,root->left,level+1);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        unordered_map<int,bool>mpp;
        vector<int>ans;
        int level=0;
        solve(ans,mpp,root,level);
        return ans;
    }
};