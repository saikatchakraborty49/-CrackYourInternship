class Node{
    public:
    int key;
    int value;
    Node* prev;
    Node* next;
    Node(int key,int value){
        this->key=key;
        this->value=value;
        prev=NULL;
        next=NULL;
    }
};

class LRUCache {
public:
    int capacity;
    Node* head;
    Node* tail;
    unordered_map<int,Node*>mpp;

    LRUCache(int capacity) {
        this->capacity=capacity;
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }

    int get(int key) {
        if(mpp.find(key)==mpp.end()) return -1;
        Node* node=mpp[key];
        node->prev->next=node->next;
        node->next->prev=node->prev;
        node->next=head->next;
        node->prev=head;
        head->next->prev=node;
        head->next=node;
        // mpp[key]=node;
        return mpp[key]->value;
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
            Node* node=mpp[key];
            node->prev->next=node->next;
            node->next->prev=node->prev;
            node->next=head->next;
            node->prev=head;
            head->next=node;
            node->next->prev=node;
            node->value=value;
            node->key=key;
            // mpp[key]=node;
        }
        else{
            if(mpp.size()==capacity){
                int toDel=tail->prev->key;
                tail->prev=tail->prev->prev;
                tail->prev->next=tail;
                mpp.erase(toDel);
            }
            Node* node=new Node(key,value);
            node->prev=head;
            node->next=head->next;
            head->next->prev=node;
            head->next=node;
            mpp[key]=node;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */