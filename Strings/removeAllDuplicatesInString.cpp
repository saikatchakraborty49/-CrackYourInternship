//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	string removeDuplicates(string str) {
	    // code here
	    vector<int>map(52,0);
	    string ans;
	    for(auto i:str){
	        if(i>='a' and i<='z'){
	            map[i-'a']++;
	            if(map[i-'a']==1)
	            ans.push_back(i);
	        }
	        else{
	            map[i-'A'+26]++;
	            if(map[i-'A'+26]==1)
	            ans.push_back(i);
	        }
	    }
	    return ans;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        auto ans = ob.removeDuplicates(str);

        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends