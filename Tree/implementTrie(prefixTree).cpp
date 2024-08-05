class TrieNode{
    public:
    char value;
    bool isTerminal;
    TrieNode* children[26];
    TrieNode(char value) {
        this->value=value;
        isTerminal=false;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
    }
};
class Trie {
public:
    TrieNode* root;
    Trie() {
        root=new TrieNode('-');
    }
    
    void insert(string word) {
        TrieNode* temp=root;
        int index=0;
        while(index!=word.size()){
            int ch=word[index]-'a';            
            if(temp->children[ch]==NULL){
                TrieNode* child=new TrieNode(word[index]);
                temp->children[ch]=child;
            }
            temp=temp->children[ch];
            if(index==word.size()-1){
                temp->isTerminal=true;
            }
            index++;
        }
    }
    
    bool search(string word) {
        TrieNode* temp=root;
        int index=0;
        while(index!=word.size()){
            int ch=word[index]-'a';            
            if(temp->children[ch]==NULL){
                return false;
            }
            temp=temp->children[ch];
            if(index==word.size()-1){
                if(temp->isTerminal) return true;
                return false;
            }
            index++;
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        TrieNode* temp=root;
        int index=0;
        while(index!=prefix.size()){
            int ch=prefix[index]-'a';            
            if(temp->children[ch]==NULL){
                return false;
            }
            temp=temp->children[ch];
            if(index==prefix.size()-1){
                return true;
            }
            index++;
        }
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */