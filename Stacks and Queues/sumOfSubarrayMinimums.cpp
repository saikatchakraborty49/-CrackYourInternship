class Solution {
private:
    int add(long long a,long long b){
        long long mod=1e9+7;
        return (a%mod+b%mod)%mod;
    }
    int mul(long long a,long long b){
        long long mod=1e9+7;
        return (a%mod*b%mod)%mod;
    }
    int bruteForce(vector<int>&nums){
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            long long mini=1e5;
            for(int j=i;j<nums.size();j++){
                if(mini>nums[j])
                mini=nums[j];
                long long mod=(1e9+7);
                sum=(sum+mini)%mod;
            }
        }
        return sum;
    }
    void findNextSmaller(vector<int>& nums,vector<int>& nextSmaller){
        stack<int>st;
        int n=nums.size();
        st.push(n);
        for(int i=n-1;i>=0;i--){
            int ele=nums[i];
            while(st.top()!=n and ele<=nums[st.top()]){
                st.pop();
            }
            nextSmaller[i]=st.top();
            st.push(i);
        }
    }
    void findPrevSmaller(vector<int>& nums,vector<int>& prevSmaller){
        stack<int>st;
        int n=nums.size();
        st.push(-1);
        for(int i=0;i<n;i++){
            int ele=nums[i];
            while(st.top()!=-1 and ele<nums[st.top()]){
                st.pop();
            }
            prevSmaller[i]=st.top();
            st.push(i);
        }
    }
public:
    int sumSubarrayMins(vector<int>& nums) {
        int n=nums.size();
        vector<int>nextSmaller(n);
        vector<int>prevSmaller(n);
        findNextSmaller(nums,nextSmaller);
        findPrevSmaller(nums,prevSmaller);
        int sum=0;
        for(int i=0;i<n;i++){
            int left=i-prevSmaller[i];
            int right=nextSmaller[i]-i;
            sum=add(sum,mul(nums[i],mul(left,right)));
        }
        return sum;
    }
};