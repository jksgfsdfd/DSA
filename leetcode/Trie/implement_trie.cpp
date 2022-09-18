class Node {
public:
    char ch;
    unordered_map<char,Node*> map;
    bool isTerminal;
    
    Node(char c){
        ch = c ;
        isTerminal = false;
    }
};

class Trie {
    
    Node* root;
    
public:
    Trie() {
        root = new Node('\0');
    }
    
    void insert(string word) {
        Node* temp = root;
        for(char ch : word){
            if(temp->map.count(ch)==0){
                temp->map[ch]=new Node(ch);
            }
            temp=temp->map[ch];
        }
        temp->isTerminal = true;
    }
    
    bool search(string word) {
        Node* temp = root;
        for(char ch : word){
            if(temp->map.count(ch)==0){
                return false;
            }
            temp=temp->map[ch];
        }
        if(temp->isTerminal){
            return true;
        }else{
            return false;
        }
    }
    
    bool startsWith(string prefix) {
        Node* temp = root;
        for(char ch : prefix){
            if(temp->map.count(ch)==0){
                return false;
            }
            temp=temp->map[ch];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
