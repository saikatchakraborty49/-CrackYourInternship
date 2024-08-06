// User function template for C++

class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        // code here
        int top=0;
        int bottom=mat.size()-1;
        while(top<bottom){
            if(mat[top][bottom]==1) top++;
            else if(mat[bottom][top]==1) bottom--;
            else{
                top++; bottom--;
            }
        }
        //check if top and bottom is a celebrity or not
        if(top!=bottom) return -1;
        for(int i=0;i<mat.size();i++){
            if(top==i) continue;
            if(mat[i][top]!=1) return -1;
        }
        for(int i=0;i<mat.size();i++){
            if(mat[top][i]==1) return -1;
        }
        return top;
    }
};