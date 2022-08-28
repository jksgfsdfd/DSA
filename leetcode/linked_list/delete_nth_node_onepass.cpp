/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size=0;
        
        ListNode* temp=head;
        unordered_map<int,ListNode*> map;
        while(temp!=NULL){
            //save index and pointer to that node in map
            map[size]=temp;
            size++;
            temp=temp->next;
        }
        int index_del=size-n;
        if(index_del==0){
            head=head->next;
            return head;
        }
        
        temp=map[index_del-1];
        temp->next=(temp->next)->next;
        return head;
    }
};
