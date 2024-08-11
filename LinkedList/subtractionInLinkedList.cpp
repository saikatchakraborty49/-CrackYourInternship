//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Node Class
class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(NULL) {}
};

// Linked List Class
class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() : head(NULL), tail(NULL) {}

    // creates a new node with given value and appends it at the end of the linked list
    void insert(int val) {
        if (head == NULL) {
            head = new Node(val);
            tail = head;
        } else {
            tail->next = new Node(val);
            tail = tail->next;
        }
    }
};


// } Driver Code Ends
//User function Template for C++

class Solution {
private:
    //reversing ka code
    Node* reverseList(Node* head) {
        if(head==NULL) return NULL;
        Node* prev=NULL;
        Node* curr=head;
        while(curr!=NULL){
            Node* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    Node* checkBigger(Node* head1,Node* head2){
        Node* temp1=head1;
        Node* temp2=head2;
        Node* ans=head2;
        while(temp1->next!=NULL and temp2->next!=NULL){
            if(temp1->data>temp2->data){
                ans=head1;
            }
            else if(temp1->data<temp2->data){
                ans=head2;
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }
        if(temp1->next!=NULL){ 
            while(temp1->next!=NULL){
                Node* newNode=new Node(0);
                temp2->next=newNode;
                temp2=temp2->next;
                temp1=temp1->next;
            }
            return head1;
        }
        else if(temp2->next!=NULL){ 
            while(temp2->next!=NULL){
                Node* newNode=new Node(0);
                temp1->next=newNode;
                temp1=temp1->next;
                temp2=temp2->next;
            }
            return head2;
        }
        else{
            if(temp1->data>temp2->data)return head1;
            else if(temp2->data>temp1->data) return head2;
            else return ans;
        }
    }
    Node* subtraction(Node* bigger,Node* smaller){
        Node* tempb=bigger;
        Node* temps=smaller;
        Node* ans=new Node(-1);
        Node* tempa=ans;
        int borrow=0;
        while(tempb!=NULL){
            int ele=(tempb->data-borrow)-temps->data;
            if(ele<0){
                ele+=10;
                borrow=1;
            }
            else{
                borrow=0;
            }
            tempa->next=new Node(ele);
            tempa=tempa->next;
            tempb=tempb->next;
            temps=temps->next;
        }
        return ans->next;
    }
public:
    Node* subLinkedList(Node* head1, Node* head2) {
        // Your implementation of subLinkedList goes here
        // Make sure to return the head of the resulting linked list
        while(head1->data==0){
            if(head1->next==NULL){
                break;
            }
            head1=head1->next;
        }
        while(head2->data==0){
            if(head2->next==NULL){
                break;
            }
            head2=head2->next;
        }
        Node* h1=reverseList(head1);
        Node* h2=reverseList(head2);
        Node* bigger=checkBigger(h1,h2);
        Node* smaller=h1;
        if(bigger==h1){
            smaller=h2;
        }
        Node* answer=reverseList(subtraction(bigger,smaller));
        while(answer->data==0){
            if(answer->next==NULL){
                break;
            }
            answer=answer->next;
        }
        return answer;
    }
};

//{ Driver Code Starts.

// prints the elements of linked list starting with head
void printList(Node* n) {
    while (n) {
        cout << n->data;
        n = n->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        LinkedList LL1;
        string l1,l2;
        cin>>l1;
        for (int j = 0; j < n; ++j) {
            int x=(l1[j]-'0');
            LL1.insert(x);
        }

        int m;
        cin >> m;
        LinkedList LL2;
        cin>>l2;
        for (int j = 0; j < m; ++j) {
            int x=(l2[j]-'0');
            LL2.insert(x);
        }

        Solution ob;
        Node* res = ob.subLinkedList(LL1.head, LL2.head);
        printList(res);
    }

    return 0;
}

// } Driver Code Ends