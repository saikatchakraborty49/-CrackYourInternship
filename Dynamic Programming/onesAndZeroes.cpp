class Solution {
private:
    int rec(int index,vector<pair<int,int>>&v,int m,int n){
        if(index==v.size()) return 0;

        //include
        int include=0;
        if(v[index].first<=m and v[index].second<=n){
            include=1+rec(index+1,v,m-v[index].first,n-v[index].second);
        }
        //exclude
        int exclude=0;
        exclude=rec(index+1,v,m,n);

        return max(include,exclude);
    }
    int mem(int index,vector<pair<int,int>>&v,int m,int n,vector<vector<vector<int>>>&dp){
        if(index==v.size()) return 0;

        if(dp[index][n][m]!=-1) return dp[index][n][m];
        //include
        int include=0;
        if(v[index].first<=m and v[index].second<=n){
            include=1+mem(index+1,v,m-v[index].first,n-v[index].second,dp);
        }
        //exclude
        int exclude=0;
        exclude=mem(index+1,v,m,n,dp);

        return dp[index][n][m]=max(include,exclude);
    }
    int tab(vector<pair<int,int>>&v,int m,int n){
        vector<vector<vector<int>>>dp(v.size()+1,vector<vector<int>>(n+1,vector<int>(m+1,0)));

        for(int i=v.size()-1;i>=0;i--){
            for(int j=0;j<=n;j++){
                for(int k=0;k<=m;k++){
                    //include
                    int include=0;
                    if(v[i].first<=k and v[i].second<=j){
                        include=1+dp[i+1][j-v[i].second][k-v[i].first];
                    }
                    //exclude
                    int exclude=0;
                    exclude=dp[i+1][j][k];
                    dp[i][j][k]=max(include,exclude);
                }
            }
        }
        return dp[0][n][m];
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int,int>>v;
        int size=strs.size();
        for(int i=0;i<size;i++){
            int zero=0;
            int one=0;
            for(auto j:strs[i]){
                if(j=='0') zero++;
                else one++;
            }
            v.push_back({zero,one});
        }
        int index=0;
        // return rec(index,v,m,n);
        // vector<vector<vector<int>>>dp(size+1,vector<vector<int>>(n+1,vector<int>(m+1,-1)));
        // return mem(index,v,m,n,dp);
        return tab(v,m,n);
    }
};