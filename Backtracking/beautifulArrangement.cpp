class Solution {
public:
    void createArray(vector<vector<int>>&ans,vector<int>&temp,vector<bool>&vis,int n){
        if(temp.size()==n){
            ans.push_back(temp);
            return ;
        }
        for(int i=1;i<=n;i++){
            if((i%(temp.size()+1)==0 or (temp.size()+1)%i==0) and vis[i]==false){
                temp.push_back(i);
                vis[i]=true;
                createArray(ans,temp,vis,n);
                temp.pop_back();
                vis[i]=false;
            }
        }
    }
    int countArrangement(int n) {
        vector<int>temp;
        vector<bool>vis(n+1);
        vector<vector<int>>ans;
        createArray(ans,temp,vis,n);
        return ans.size();
    }
};