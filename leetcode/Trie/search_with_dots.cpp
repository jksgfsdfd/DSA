class Node {
public:
    char ch;
    Node* list[26];
    bool isTerminal;
    
    Node(char c){
        ch = c;
        isTerminal = false;
        memset(list,NULL,sizeof(list));
    }
};

class WordDictionary {
    
    Node* root;
    
public:
    WordDictionary() {
        root = new Node('\0');    
    }
    
    void addWord(string word) {
        Node* temp = root;
        for(char c : word){
            if(temp->list[c-'a']==NULL){
                temp->list[c-'a'] = new Node(c);
            }
            temp=temp->list[c-'a'];
        }
        temp->isTerminal = true;
    }
    
    bool newsearch(string word,int index,Node* rootie){
        if(index==word.length()){
            if(rootie->isTerminal){
                return true;
            }else{
                return false;
            } 
        }
        Node* temp=rootie;
        if(word[index]=='.'){
            for(int i=0;i<26;i++){
                if(temp->list[i]==NULL){
                    continue;
                }
                bool ans = newsearch(word,index+1,temp->list[i]);
                if(ans){
                    return true;
                }
            }
            return false;
        }else if(temp->list[word[index]-'a']==NULL){
            return false;
        }else{
            return newsearch(word,index+1,temp->list[word[index]-'a']);
        }
    }
    
    bool search(string word) {
        return newsearch(word,0,root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
