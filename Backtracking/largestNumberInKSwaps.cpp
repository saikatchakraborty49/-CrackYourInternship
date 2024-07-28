//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    private:
    void solve(int index,int swaps,string &str,int &k,string &ans){
        if(index==str.size() or swaps==k){
            return ;
        }
        int maxChar=index;
        for(int i=index+1;i<str.size();i++){
            maxChar=str[i]>str[maxChar]?i:maxChar;
        }
        if(str[maxChar]!=str[index]){
        for(int i=index;i<str.size();i++){
            if(str[i]==str[maxChar]){
                swap(str[i],str[index]);
                if(ans<str) ans=str;
                solve(index+1,swaps+1,str,k,ans);
                swap(str[i],str[index]);
            }
        }}
        else{
            solve(index+1,swaps,str,k,ans);
        }
        
    }
    public:
    //Function to find the largest number after k swaps.
    string findMaximumNum(string str, int k)
    {
       // code here.
       string ans=str;
       int index=0;
       int swaps=0;
       solve(index,swaps,str,k,ans);
       return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}

// } Driver Code Ends