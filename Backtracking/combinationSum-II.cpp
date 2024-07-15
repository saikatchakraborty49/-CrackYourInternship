class Solution {
public:
    void f(vector<vector<int>>&ans,vector<int>&temp,vector<int>&candidates,int target,int index,int sum){
        if(sum==target){
            ans.push_back(temp);
            return ;
        }
        if(sum>target || index==candidates.size()){
            return;
        }
        //include
        sum=sum+candidates[index];
        temp.push_back(candidates[index]);
        f(ans,temp,candidates,target,index+1,sum);
        sum=sum-candidates[index];
        temp.pop_back();
        //exclude
        while(index+1<candidates.size() and candidates[index]==candidates[index+1]) index++;
        f(ans,temp,candidates,target,index+1,sum);
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int sum=0;
        int index=0;
        vector<vector<int>> ans;
        vector<int>temp;
        sort(candidates.begin(),candidates.end());
        f(ans,temp,candidates,target,index,sum);
        return ans;
    }
};