//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool usingBFS(int src,unordered_map<int,bool>&visited,unordered_map<int,int>&parent,vector<int> adj[]){
        visited[src]=true;
        parent[src]=-1;
        queue<int>q;
        q.push(src);
        while(!q.empty()){
            int front=q.front();
            q.pop();
            for(auto i:adj[front]){
                if(!visited[i]){
                    q.push(i);
                    visited[i]=true;
                    parent[i]=front;
                }
                else{
                    if(i!=parent[front]) return true;
                }
            }
        }
        return false;
    }
    bool usingDFS(int src,unordered_map<int,bool>&visited,int parent,vector<int> adj[]){
        visited[src]=true;
        for(auto i:adj[src]){
            if(!visited[i]){
                bool ans=usingDFS(i,visited,src,adj);
                if(ans) return true;
            }
            else if(visited[i] and i!=parent){
                return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        unordered_map<int,bool>visited;
        unordered_map<int,int>parent;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                // bool ans=usingBFS(i,visited,parent,adj);
                visited[i]=true;
                bool ans=usingDFS(i,visited,-1,adj);
                if(ans) return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends