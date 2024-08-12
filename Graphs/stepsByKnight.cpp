//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    bool isSafe(int newRow,int newCol,int N,vector<vector<bool>>&vis){
        if(newRow>=1 and newRow<=N and newCol>=1 and newCol<=N and vis[newRow][newCol]==false) return true;
        return false;
    }
    
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    if(KnightPos==TargetPos) return 0;
        int sr=KnightPos[0];
        int sc=KnightPos[1];
        int dr=TargetPos[0];
        int dc=TargetPos[1];
        int ans=0;
        queue<pair<pair<int,int>,int>>q;
        q.push({{sr,sc},0});
        vector<vector<bool>>vis(N+1,vector<bool>(N+1,false));
        vector<pair<int,int>>moves{{1,2},{2,1},{-1,2},{-2,1},{1,-2},{2,-1},{-1,-2},{-2,-1}};
        while(!q.empty()){
            auto top=q.front();
            q.pop();
            int row=top.first.first;
            int col=top.first.second;
            int dist=top.second;
            for(auto i:moves){
                int newRow=row+i.first;
                int newCol=col+i.second;
                if(isSafe(newRow,newCol,N,vis)){
                    vis[newRow][newCol]=true;
                    q.push({{newRow,newCol},dist+1});
                    ans=dist+1;
                }
                if(newRow==dr and newCol==dc){
                    return ans;
                }
            }
        }
        return -1;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends