class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mpp;
        for(auto s:strs){
            string dummy=s;
            sort(dummy.begin(),dummy.end());
            mpp[dummy].push_back(s);
        }
        vector<vector<string>>ans;
        for(auto i:mpp){
            ans.push_back(i.second);
        }
        return ans;
    }
};