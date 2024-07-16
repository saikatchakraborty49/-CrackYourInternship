class Solution {
public:
    void f(int index,vector<vector<int>>&ans,vector<int>&temp,int n,int k){
        if(temp.size()==k){
            ans.push_back(temp);
            return ;
        }
        for(int i=index;i<=n;i++){
            temp.push_back(i);
            f(i+1,ans,temp,n,k);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>temp;
        int index=1;
        vector<vector<int>> ans;
        f(index,ans,temp,n,k);
        return ans;
    }
};