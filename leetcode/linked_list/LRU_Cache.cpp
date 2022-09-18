class MyNode {
public:
    int key;
    MyNode* next;
    MyNode* prev;
    
    MyNode(int key){
        this->key=key;
    }
};

class LRUCache {
    int capacity;
    int size;
    MyNode* head;
    MyNode* tail;
    unordered_map<int,pair<int,MyNode*>> map;
public:
    LRUCache(int capacity) {
        this->capacity=capacity;
        this->size=0;
        this->head=NULL;
        this->tail=NULL;
    }
    
    int get(int key) {
        //search in map and update the nodes position in the list
        if(map.find(key)==map.end()){
            return -1;
        }
        MyNode* temp=map[key].second;
        //check error for first and last element
        
        if(head==tail){
            //do nothing 
            return map[key].first;
        }
        
        if(temp==head){
            temp->next->prev=NULL;
            tail->next=temp;
            temp->prev=tail;
            tail=temp;
            head=temp->next;
            temp->next=NULL;
        }else if(temp==tail){
            //do nothing
            return map[key].first;
        }else{

            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
        
            tail->next=temp;
            temp->prev=tail;
            temp->next=NULL;
            tail=temp;
            
        }
        return map[key].first;
        
    }
    
    void put(int key, int value) {
        //key is already present
        if(map.find(key)!=map.end()){
            map[key].first=value;
            map[key].second->key=key;
            MyNode* temp=map[key].second;
            int val=get(key);
            return;
        }
        
        if(size==capacity){
            //remove head
            //cout<<"tail key is"<<tail->key<<"head key is"<<head->key<<endl;
            map.erase(head->key);
            head->key=key;
            map[key]={value,head};
            tail->next=head;
            head->prev=tail;
            head->next->prev=NULL;
            head=head->next;
            tail=tail->next;
            tail->next=NULL;
            
        }else if(size==0){
            size++;
            head = new MyNode(key);
            head->prev=NULL;
            head->next=NULL;
            tail=head;
            map[key]={value,head};
        }else{
            size++;
            tail->next= new MyNode(key);
            map[key]={value,tail->next};
            tail->next->next=NULL;
            tail->next->prev=tail;
            tail=tail->next;
           // cout<<"tail key is"<<tail->key<<"head key is"<<head->key<<endl;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
