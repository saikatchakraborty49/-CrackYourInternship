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
    void solve(vector<string>&ans,string &temp,TreeNode* root){
        if(root==NULL){
            return ;
        }        
        if(root->left==NULL and root->right==NULL){
            string str=to_string(root->val);
            temp+=str;
            int n=str.size();
            ans.push_back(temp);
            while(n--)
            temp.pop_back();
            return ;
        }
        string str=to_string(root->val);
        str+="->";
        int n=str.size();
        temp+=str;
        solve(ans,temp,root->left);
        solve(ans,temp,root->right);
        while(n--){
            temp.pop_back();
        }
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        string temp;
        solve(ans,temp,root);
        return ans;
    }
};