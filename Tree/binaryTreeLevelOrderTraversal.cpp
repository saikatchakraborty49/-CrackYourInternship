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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL) return {};
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        vector<vector<int>>ans;
        while(q.size()>1){
            vector<int>temp;
            TreeNode* front=q.front();
            while(front!=NULL){
                temp.push_back(front->val);
                if(front->left!=NULL)
                q.push(front->left);
                if(front->right!=NULL)
                q.push(front->right);
                q.pop();
                front=q.front();
            }
            if(front==NULL){
            q.pop();
            q.push(NULL);
            }
            if(!temp.empty())
            ans.push_back(temp);
        }
        return ans;
    }
};