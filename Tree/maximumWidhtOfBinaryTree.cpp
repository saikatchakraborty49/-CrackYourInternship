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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});
        long long answer=0;
        while(q.size()!=0){
            long long size=q.size();
            long long first;
            long long last;
            //isse kuch farak naa padogo
            //bas overflow avoid karogo
            long long mMin=q.front().second;
            for(int i=0;i<size;i++){
                auto front=q.front();
                q.pop();
                if(i==0) first=front.second-mMin;
                if(i==size-1) last=front.second-mMin;
                
                if(front.first->left!=NULL)
                q.push({front.first->left,(front.second-mMin)*2+1});
                if(front.first->right!=NULL)
                q.push({front.first->right,(front.second-mMin)*2+2});
            }
            answer=max(answer,last-first+1);
        }
        return answer;
    }
};