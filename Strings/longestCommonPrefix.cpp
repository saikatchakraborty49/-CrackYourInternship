class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        for(int j=0;j<strs[0].size();j++){
            char ch=strs[0][j];
            for(int i=1;i<strs.size();i++){
                if(strs[i][j]!=ch) return ans;
            }
            ans.push_back(ch);
        }
        return ans;
    }
};