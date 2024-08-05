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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL) return {};
        queue<TreeNode*>q;
        vector<vector<int>>ans;
        q.push(root);
        q.push(NULL);
        int row=1;
        ans.push_back({root->val});
        vector<int>temp;
        while(q.size()!=1){
            TreeNode* front=q.front();
            q.pop();
            if(front!=NULL){                
                if(front->left) {
                    q.push(front->left);
                    temp.push_back(front->left->val);
                }
                if(front->right) {
                    q.push(front->right);
                    temp.push_back(front->right->val);
                }
            }            
            else if(front==NULL) {
                q.push(NULL);
                if(row%2==1) reverse(temp.begin(),temp.end());
                ans.push_back(temp);
                while(temp.size()!=0) temp.pop_back();
                row++;
            }            
        }
        return ans;
    }
};