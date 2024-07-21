class Solution {
private:
    int remainingSum(string s,vector<int>&map){
        int maxi=0;
        int sum=0;
        for(int i=0;i<map.size();i++){
            sum+=map[i];
            maxi=max(maxi,map[i]);
        }
        return sum-maxi;
    }
public:
    int characterReplacement(string s, int k) {
        vector<int>map(26,0);
        int ans=0;
        int i=0;
        int j=0;
        int kCnt=0;
        while(i<s.size() and j<s.size()){
            map[s[j]-'A']++;
            kCnt=remainingSum(s,map);
            // cout<<"i->"<<i<<" j->"<<j<<" kCnt->"<<kCnt<<endl;
            if(kCnt<=k){
                ans=max(ans,j-i+1);
                j++;
            }
            else{
                map[s[i]-'A']--;
                map[s[j]-'A']--;
                i++;
            }
        }
        // for(int i=0;i<s.size();i++){
        //     int kCnt=0;
        //     for(int j=i;j<s.size();j++){
        //         map[s[j]-'A']++;
        //         kCnt=remainingSum(s,map);
        //         cout<<"i->"<<i<<" j->"<<j<<" kCnt->"<<kCnt<<endl;
        //         if(kCnt<=k){
        //             ans=max(ans,j-i+1);
        //         }
        //         else{
        //             break;
        //         }
        //     }
        //     fill(map.begin(),map.end(),0);
        // }
        return ans;
    }
};