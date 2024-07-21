//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>

using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        temp = new Node(val);
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}




int getCountOfNode(Node *root, int l, int h)
{

    if (!root) return 0;


    if (root->data == h && root->data == l)
        return 1;

    if (root->data <= h && root->data >= l)
         return 1 + getCountOfNode(root->left, l, h) +
                    getCountOfNode(root->right, l, h);

    else if (root->data < l)
         return getCountOfNode(root->right, l, h);


    else return getCountOfNode(root->left, l, h);
}


// } Driver Code Ends
/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/

/*You are required to complete below method */
class Solution{
    private:
    void findInorder(Node* root,vector<int>&inorder){
        if(root==NULL) return ;
        //left
        findInorder(root->left,inorder);
        //node
        inorder.push_back(root->data);
        //right
        findInorder(root->right,inorder);
    }
    void findLeafNode(Node* root,vector<int>&leafNode){
        if(root==NULL) return ;
        
        //left
        findLeafNode(root->left,leafNode);
        //node
        if(root->left==NULL and root->right==NULL){
            leafNode.push_back(root->data);
            return ;
        }
        //right
        findLeafNode(root->right,leafNode);
    }
    bool checkIfDeadEnd(vector<int>&inorder,vector<int>&leafNode){
        int inorderIndex=1;
        int leafNodeIndex=0;
        while(leafNodeIndex<leafNode.size()){
            while(leafNode[leafNodeIndex]!=inorder[inorderIndex]){
                inorderIndex++;
            }
            leafNodeIndex++;
            if(inorder[inorderIndex]-inorder[inorderIndex-1]<=1 and inorder[inorderIndex+1]-inorder[inorderIndex]<=1)
            return true;
        }
        return false;
    }
    public:
    bool isDeadEnd(Node *root)
    {
        //Your code here
        vector<int>inorder;
        inorder.push_back(0);
        findInorder(root,inorder);
        inorder.push_back(inorder.back()+2);
        vector<int>leafNode;
        findLeafNode(root,leafNode);
        return checkIfDeadEnd(inorder,leafNode);
    }
};

//{ Driver Code Starts.
// bool isDeadEnd(Node *root);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node *root;
        Node *tmp;
    //int i;

        root = NULL;

        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
            insert(&root, k);

        }

     Solution ob;
     cout<<ob.isDeadEnd(root);
     cout<<endl;
    }
}


// } Driver Code Ends