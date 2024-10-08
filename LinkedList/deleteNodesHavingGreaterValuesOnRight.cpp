//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    private:
    void solve(Node* prev,Node* curr,int &maxi,Node* &ans){
        if(curr==NULL) return;
        solve(curr,curr->next,maxi,ans);
        if(curr->data<maxi){
            if(prev==NULL){
                curr=curr->next;
            }
            else
            prev->next=curr->next;
        }
        maxi=max(maxi,curr->data);
        ans=curr;
    }
    public:
    Node *compute(Node *head)
    {
        // your code goes here
        Node* ans=NULL;
        Node* prev=NULL;
        Node* curr=head;
        int maxi=0;
        solve(prev,curr,maxi,ans);
        return ans;
    }
    
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends