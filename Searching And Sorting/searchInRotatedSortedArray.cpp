class Solution {
private:
    int findPivot(vector<int>&nums){
        int pivot=-1;
        int s=0;
        int e=nums.size()-1;
        int mid=s+(e-s)/2;
        while(s<e){
            //FOR SORTED PART
            if(nums[mid]>=nums[s] and nums[mid]<=nums[e]) return e;
            if(nums[mid]<=nums[s]) e=mid-1;
            else{
                s=mid;
            }
            mid=s+(e-s)/2;
        }
        return s;
    }
    int binarySearch(int s,int e,vector<int>&nums,int target){
        int mid=s+(e-s)/2;
        while(s<=e){
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
            mid=s+(e-s)/2;
        }
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        int pivot=findPivot(nums);
        cout<<pivot<<endl;
        int left=binarySearch(0,pivot,nums,target);
        int right=binarySearch(pivot+1,nums.size()-1,nums,target);
        if(left==-1 and right==-1) return -1;
        else if(left!=-1) return left;
        else return right;
    }
};