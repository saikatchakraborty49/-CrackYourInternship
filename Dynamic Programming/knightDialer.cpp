class Solution {
private:
    int rec(int n,int row,int col){
        if(row == 3 && (col == 0 || col == 2)) return 0;
        if(n==1) return 1;
        int ans=0;
        //left-down
        if(row-1>=0 and row-1<=3 and col-2>=0 and col-2<=2 and !(row == 3 && (col == 0 || col == 2))){
            ans+=rec(n-1,row-1,col-2);
        }
        //left-up
        if(row+1>=0 and row+1<=3 and col-2>=0 and col-2<=2 and !(row == 3 && (col == 0 || col == 2))){
            ans+=rec(n-1,row+1,col-2);
        }
        //right-up
        if(row+1>=0 and row+1<=3 and col+2>=0 and col+2<=2 and !(row == 3 && (col == 0 || col == 2))){
            ans+=rec(n-1,row+1,col+2);
        }
        //right-down
        if(row-1>=0 and row-1<=3 and col+2>=0 and col+2<=2 and !(row == 3 && (col == 0 || col == 2))){
            ans+=rec(n-1,row-1,col+2);
        }
        //top-left
        if(row+2>=0 and row+2<=3 and col-1>=0 and col-1<=2 and !(row == 3 && (col == 0 || col == 2))){
            ans+=rec(n-1,row+2,col-1);
        }
        //top-right
        if(row+2>=0 and row+2<=3 and col+1>=0 and col+1<=2 and !(row == 3 && (col == 0 || col == 2))){
            ans+=rec(n-1,row+2,col+1);
        }
        //down-left
        if(row-2>=0 and row-2<=3 and col-1>=0 and col-1<=2 and !(row == 3 && (col == 0 || col == 2))){
            ans+=rec(n-1,row-2,col-1);
        }
        //down-right
        if(row-2>=0 and row-2<=3 and col+1>=0 and col+1<=2 and !(row == 3 && (col == 0 || col == 2))){
            ans+=rec(n-1,row-2,col+1);
        }
        return ans;
    }
    int mem(int n,int row,int col,vector<vector<vector<int>>>&dp){
        if(row == 3 && (col == 0 || col == 2)) return 0;
        if(n==1) return 1;
        if(dp[n][row][col]!=-1) return dp[n][row][col];
        long long ans=0;
        //left-down
        if(row-1>=0 and row-1<=3 and col-2>=0 and col-2<=2 and !(row == 3 && (col == 0 || col == 2))){
            ans=add(ans,mem(n-1,row-1,col-2,dp));
        }
        //left-up
        if(row+1>=0 and row+1<=3 and col-2>=0 and col-2<=2 and !(row == 3 && (col == 0 || col == 2))){
            ans=add(ans,mem(n-1,row+1,col-2,dp));
        }
        //right-up
        if(row+1>=0 and row+1<=3 and col+2>=0 and col+2<=2 and !(row == 3 && (col == 0 || col == 2))){
            ans=add(ans,mem(n-1,row+1,col+2,dp));
        }
        //right-down
        if(row-1>=0 and row-1<=3 and col+2>=0 and col+2<=2 and !(row == 3 && (col == 0 || col == 2))){
            ans=add(ans,mem(n-1,row-1,col+2,dp));
        }
        //top-left
        if(row+2>=0 and row+2<=3 and col-1>=0 and col-1<=2 and !(row == 3 && (col == 0 || col == 2))){
            ans=add(ans,mem(n-1,row+2,col-1,dp));
        }
        //top-right
        if(row+2>=0 and row+2<=3 and col+1>=0 and col+1<=2 and !(row == 3 && (col == 0 || col == 2))){
            ans=add(ans,mem(n-1,row+2,col+1,dp));
        }
        //down-left
        if(row-2>=0 and row-2<=3 and col-1>=0 and col-1<=2 and !(row == 3 && (col == 0 || col == 2))){
            ans=add(ans,mem(n-1,row-2,col-1,dp));
        }
        //down-right
        if(row-2>=0 and row-2<=3 and col+1>=0 and col+1<=2 and !(row == 3 && (col == 0 || col == 2))){
            ans=add(ans,mem(n-1,row-2,col+1,dp));
        }
        return dp[n][row][col]=ans;
    }
    int add(long long a,long long b){
        long long mod=1000000007;
        return (a%mod+b%mod)%mod;
    }
public:
    int knightDialer(int n) {
        int ans=0;
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(5,vector<int>(5,-1)));
        for(int i=0;i<4;i++){
            for(int j=0;j<3;j++){
                ans=add(ans,mem(n,i,j,dp));
            }
        }
        return ans;
    }
};