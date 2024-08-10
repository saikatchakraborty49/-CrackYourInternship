/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markParents(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&parent){
        if(root==NULL) return ;
        if(root->left){
            parent[root->left]=root;
            markParents(root->left,parent);
        }
        if(root->right){
            parent[root->right]=root;
            markParents(root->right,parent);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>parent;
        markParents(root,parent);
        unordered_map<TreeNode*,bool>visited;
        queue<TreeNode*>q;
        q.push(target);
        visited[target]=true;
        int currLevel=0;
        while(!q.empty()){
            int size=q.size();
            if(currLevel==k) break;
            currLevel++;
            for(int i=0;i<size;i++){
                TreeNode* front=q.front();
                q.pop();
                if(front->left and visited[front->left]==false){
                    q.push(front->left);
                    visited[front->left]=true;
                }
                if(front->right and visited[front->right]==false){
                    q.push(front->right);
                    visited[front->right]=true;
                }
                if(parent[front] and visited[parent[front]]==false){
                    q.push(parent[front]);
                    visited[parent[front]]=true;
                }
            }
        }
        vector<int>ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};