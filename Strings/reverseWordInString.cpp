class Solution {
private:
    void reverse(int i,int j,string &s){
        while(i<j){
            swap(s[i],s[j]);
            i++; j--;
        }
    }
public:
    string reverseWords(string s) {
        int n=s.size();
        s.push_back(' ');
        reverse(0,n,s);
        s.push_back(' ');
        n+=2;
        int prevWord=1;
        for(int i=1;i<=n;i++){
            if(s[i]==' '){
                while(s[prevWord]==' ') {
                    prevWord++;
                }
                reverse(prevWord,i-1,s);
                prevWord=i;
            }
        }
        for(int i=1;i<s.size();i++){
            if(i<s.size() and s[i]==' ' and s[i-1]==' '){
                while(i<s.size() and s[i]==' ' and s[i-1]==' '){
                    s.erase(s.begin()+i);
                }
            }
        }
        s.erase(s.begin());
        s.erase(s.begin()+s.size()-1);
        return s;
    }
};