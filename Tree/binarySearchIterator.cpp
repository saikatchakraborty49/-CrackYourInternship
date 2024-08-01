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
class BSTIterator {
public:
    TreeNode* root;
    vector<int>inorder;
    void inorderTraversal(TreeNode* root,vector<int>&inorder){
        if(root==NULL) return ;
        inorderTraversal(root->left,inorder);
        inorder.push_back(root->val);
        inorderTraversal(root->right,inorder);
    }
    BSTIterator(TreeNode* root) {
        this->root=root;
        inorderTraversal(root,inorder);
        reverse(inorder.begin(),inorder.end());
        for(auto i:inorder){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    int next() {
        if(inorder.size()>0){
            int back=inorder.back();
            inorder.pop_back();
            return back;
        }
        return -1;
    }
    
    bool hasNext() {
        if(inorder.size()>0){
            return true;
        }
        else return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */