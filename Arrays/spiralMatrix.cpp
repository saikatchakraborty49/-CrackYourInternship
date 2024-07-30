class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rowStart=0;
        int rowEnd=matrix.size()-1;
        int colStart=0;
        int colEnd=matrix[0].size()-1;
        int n=matrix.size();
        int m=matrix[0].size();
        int ele=0;
        vector<int>ans;
        while(ele!=n*m){
            for(int i=colStart;i<=colEnd;i++){
                if(ele>=n*m) break;
                ans.push_back(matrix[rowStart][i]);
                ele++;
            }
            rowStart++;
            for(int i=rowStart;i<=rowEnd;i++){
                if(ele>=n*m) break;
                ans.push_back(matrix[i][colEnd]);
                ele++;
            }
            colEnd--;
            for(int i=colEnd;i>=colStart;i--){
                if(ele>=n*m) break;
                ans.push_back(matrix[rowEnd][i]);
                ele++;
            }
            rowEnd--;
            for(int i=rowEnd;i>=rowStart;i--){
                if(ele>=n*m) break;
                ans.push_back(matrix[i][colStart]);
                ele++;
            }
            colStart++;
        }
        return ans;
    }
};