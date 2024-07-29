class Solution {
private:
    int isPossible(int target,int start,vector<int>&stones){
        int end=stones.size()-1;
        int mid=start+(end-start)/2;
        while(start<=end){
            if(stones[mid]==target) return mid;
            else if(stones[mid]>target) end=mid-1;
            else start=start+1;
            mid=start+(end-start)/2;
        }
        return -1;
    }
    bool rec(int index,int prevJump,vector<int>& stones){
        if(index==stones.size()-1) return true;
        bool ans1=false;
        bool ans2=false;
        bool ans3=false;
        int mid=-1;
        if(prevJump-1>=0 and (mid=isPossible((prevJump-1+stones[index]),index+1,stones))!=-1){
            ans1=rec(mid,prevJump-1,stones);
        }
        if((mid=(isPossible(prevJump+1+stones[index],index+1,stones)))!=-1){
            // cout<<mid<<endl;
            ans2=rec(mid,prevJump+1,stones);
        }
        if((mid=(isPossible(prevJump+stones[index],index+1,stones)))!=-1){
            ans3=rec(mid,prevJump,stones);
        }
        return ans1 or ans2 or ans3;
    }
    bool mem(int index,int prevJump,vector<int>& stones,vector<vector<int>>&dp){
        if(index==stones.size()-1) return true;
        if(dp[index][prevJump]!=-1) return dp[index][prevJump];
        bool ans1=false;
        bool ans2=false;
        bool ans3=false;
        int mid=-1;
        if(prevJump-1>=0 and (mid=isPossible(prevJump-1+stones[index],index+1,stones))!=-1){
            ans1=mem(mid,prevJump-1,stones,dp);
        }
        if((mid=(isPossible(prevJump+1+stones[index],index+1,stones)))!=-1){
            ans2=mem(mid,prevJump+1,stones,dp);
        }
        if((mid=(isPossible(prevJump+stones[index],index+1,stones)))!=-1){
            ans3=mem(mid,prevJump,stones,dp);
        }
        return dp[index][prevJump]=ans1 or ans2 or ans3;
    }
    bool tab(vector<int>& stones){
        int n=stones.size();
        vector<vector<bool>>dp(n+1,vector<bool>(2001,true));

        for(int i=n-2;i>=0;i--){
            for(int prevJump=i;prevJump>=0;prevJump--){
                int mid=-1; 
                bool ans1=false;
                bool ans2=false;
                bool ans3=false;
                if(prevJump-1>=0 and (mid=isPossible(prevJump-1+stones[i],i+1,stones))!=-1){
                    ans1=dp[mid][prevJump-1];
                }
                if((mid=(isPossible(prevJump+1+stones[i],i+1,stones)))!=-1){
                    ans2=dp[mid][prevJump+1];
                }
                if((mid=(isPossible(prevJump+stones[i],i+1,stones)))!=-1){
                    ans3=dp[mid][prevJump];
                }
                dp[i][prevJump]=ans1 or ans2 or ans3;
            }
        }
        return dp[0][0];
    }
public:
    bool canCross(vector<int>& stones) {
        int index=0;
        int prevJump=0;
        int n=stones.size();
        // return rec(index,prevJump,stones);
        // vector<vector<int>>dp(n+1,vector<int>(2001,-1));
        // return mem(index,prevJump,stones,dp);
        return tab(stones);
    }
};