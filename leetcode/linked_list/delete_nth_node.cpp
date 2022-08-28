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
        while(temp!=NULL){
            size++;
            temp=temp->next;
        }
        int index_del=size-n;
        if(index_del==0){
            head=head->next;
            return head;
        }
        
        temp=head;
        while(--index_del){
            temp=temp->next;
        }
        temp->next=(temp->next)->next;
        return head;
    }
};
