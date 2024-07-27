class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int deficit=0;
        int balance=0;
        int ans=0;
        for(int i=0;i<gas.size();i++){
            balance+=gas[i]-cost[i];
            if(balance<0){
                deficit+=-1*balance;
                balance=0;
                ans=i+1;
            }
        }
        if(balance-deficit>=0) return ans;
        else return -1;
    }
};