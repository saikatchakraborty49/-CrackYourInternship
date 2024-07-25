//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    private:
    vector<int>byBFS(int V,vector<int>adj[]){
        vector<int>ans;
	    //maintain inorder
	    unordered_map<int,int>inorder;
	    for(int i=0;i<V;i++){
	        for(auto nbr:adj[i]){
	            inorder[nbr]++;
	        }
	    }
	    //push all inorder 0 wala node in queue
	    queue<int>q;
	    for(int node=0;node<V;node++){
	        if(inorder[node]==0){
	            q.push(node);
	        }
	    }
	    while(!q.empty()){
	        int front=q.front();
	        q.pop();
	        ans.push_back(front);
	        for(auto nbr:adj[front]){
	            inorder[nbr]--;
	            if(inorder[nbr]==0)
	            q.push(nbr);
	        }
	    }
	    return ans;
    }
    void byDFS(int src,int V,vector<int> adj[],stack<int>&st,unordered_map<int,bool>&visited){
        visited[src]=1;
        for(auto nbr:adj[src]){
            if(!visited[nbr]){
                byDFS(nbr,V,adj,st,visited);
            }
        }
        st.push(src);
    }
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
       // code here
	   // return byBFS(V,adj);
	   unordered_map<int,int>inorder;
	    for(int i=0;i<V;i++){
	        for(auto nbr:adj[i]){
	            inorder[nbr]++;
	        }
	    }
	    stack<int>st;
	    unordered_map<int,bool>visited;
	    for(int node=0;node<V;node++){
	        if(inorder[node]==0){
	            byDFS(node,V,adj,st,visited);
	        }
	    }
	    vector<int>ans;
	    while(!st.empty()){
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends