class Solution {
public:
    string addBinary(string a, string b) {
        int carry=0;
        int eleA=0;
        int eleB=0;
        string ans;
        int nA=a.size()-1;
        int nB=b.size()-1;
        while(nA>=0 and nB>=0){
            eleA=a[nA]-'0';
            eleB=b[nB]-'0';
            int sum=eleA+eleB+carry;
            if(sum==0 || sum==1){
                ans.push_back(sum+'0');
                carry=0;
            }
            else if(sum==2){
                ans.push_back('0');
                carry=1;
            }
            else if(sum==3){
                ans.push_back('1');
                carry=1;
            }
            nA--;
            nB--;
        }
        while(nA>=0){
            eleA=a[nA]-'0';
            int sum=eleA+carry;
            if(sum==0 || sum==1){
                ans.push_back(sum+'0');
                carry=0;
            }
            else if(sum==2){
                ans.push_back('0');
                carry=1;
            }
            else if(sum==3){
                ans.push_back('1');
                carry=1;
            }
            nA--;
        }
        while(nB>=0){
            eleB=b[nB]-'0';
            int sum=eleB+carry;
            if(sum==0 || sum==1){
                ans.push_back(sum+'0');
                carry=0;
            }
            else if(sum==2){
                ans.push_back('0');
                carry=1;
            }
            else if(sum==3){
                ans.push_back('1');
                carry=1;
            }
            nB--;
        }
        if(carry==1) ans.push_back('1');
        reverse(ans.begin(),ans.end());
        return ans;
    }
};