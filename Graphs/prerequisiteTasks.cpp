class Solution {
public:
    bool detectCycle(unordered_map<int,bool>&visited,unordered_map<int,bool>&dfsVisited,int src,unordered_map<int,vector<int>>&adjList){
        visited[src]=true;
        dfsVisited[src]=true;
        for(auto nbr:adjList[src]){
            if(!visited[nbr]){
            bool ans=detectCycle(visited,dfsVisited,nbr,adjList);
            if(ans) return true;}
            if(dfsVisited[nbr]) return true;
        }
        dfsVisited[src]=false;
        return false;
    }
	bool isPossible(int N,int P, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    unordered_map<int,vector<int>>adjList;
	    for(auto i:prerequisites){
	        int u=i.first;
	        int v=i.second;
	        
	        adjList[u].push_back(v);
	    }
	    unordered_map<int,bool>visited;
	    unordered_map<int,bool>dfsVisited;
	    for(int i=0;i<N;i++){
	        bool ans=false;
	        if(visited[i]==false){
	            bool ans=detectCycle(visited,dfsVisited,i,adjList);
	            if(ans==true) return false;
	        }
	    }
	    return true;
	}
};