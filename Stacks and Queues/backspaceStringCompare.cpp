class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<int>stS;
        stack<int>stT;
        for(auto i:s){
            if(i!='#') stS.push(i);
            else{
                if(!stS.empty())
                stS.pop();
            }
        }
        for(auto i:t){
            if(i!='#') stT.push(i);
            else{
                if(!stT.empty())
                stT.pop();
            }
        }
        while(!stS.empty() and !stT.empty()){
            int eleS=stS.top(); stS.pop();
            int eleT=stT.top(); stT.pop();
            if(eleS!=eleT)return false;
        }
        if(!stS.empty() || !stT.empty()) return false;
        return true;
    }
};