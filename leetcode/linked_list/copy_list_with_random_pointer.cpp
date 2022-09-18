/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp;
        unordered_map<int,Node*> map_new;
        unordered_map<Node*,int> map_old;
        int index=0;
        Node* new_head;
        Node* new_temp;
        
        //initialise new head
        if(head){
            new_head=new Node(head->val);
        }else{
            return head;
        }
        
        temp=head->next;
        new_temp=new_head;
        map_new[index]=new_temp;
        map_old[head]=index;
        index++;
        
        
        while(temp){
            map_old[temp]=index;
            new_temp->next=new Node(temp->val);
            temp=temp->next;
            new_temp=new_temp->next;
            map_new[index]=new_temp;
            index++;
        }
        
        temp=head;
        new_temp=new_head;
        while(temp){
            if(temp->random==NULL){
                new_temp->random=NULL;
                temp=temp->next;
                new_temp=new_temp->next;
                continue;
            }else{
                int index=map_old[temp->random];
                new_temp->random=map_new[index];
                temp=temp->next;
                new_temp=new_temp->next;
            }
        }
        
        return new_head;
        
        
        
    }
};
