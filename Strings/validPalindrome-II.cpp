class Solution {
private:
    bool checkPalindrome(int i,int j,string s){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;j--;
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        int start=0;
        int end=s.size()-1;
        while(start<end){
            if(s[start]==s[end]){
                start++;
                end--;
            }
            else{
                int ans1=checkPalindrome(start+1,end,s);
                int ans2=checkPalindrome(start,end-1,s);
                return ans1 or ans2;
            }
        }
        return true;
    }
};