class comp{
    public:
    bool operator()(pair<int,char>a,pair<int,char>b){
        return a.first<b.first;
    }
};
class Solution {
public:
    string reorganizeString(string s) {
        //create a maxHeap
        priority_queue<pair<int,char>,vector<pair<int,char>>,comp>pq;
        //create freq array
        vector<int>freq(26,0);
        for(int i=0;i<s.size();i++){
            freq[s[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            char ch=i+'a';
            if(freq[i]!=0)
            pq.push({freq[i],ch});
        }
        string ans;
        while(pq.size()>1){
            auto a=pq.top(); pq.pop();
            auto b=pq.top(); pq.pop();
            ans.push_back(a.second);
            ans.push_back(b.second);
            a.first--;
            b.first--;
            if(a.first>0) pq.push(a);
            if(b.first>0) pq.push(b);
        }
        if(pq.empty()) return ans;
        if(pq.top().first==1){
            ans.push_back(pq.top().second);
            return ans;
        }
        else
        return "";
    }
};