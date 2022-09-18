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
        stack<ListNode*> stk;
        ListNode* temp=head;
        while(temp){
            stk.push(temp);
            temp=temp->next;
        }
        
        int counter=n;
        while(--counter){
            stk.pop();
        }
        
        //check if removing element is first element
        if(stk.empty()){
            return head;
        }
        temp=stk.top()->next;
        stk.pop();
        if(stk.empty()){
            //removing ele is first ele
            head=temp;
            return head;
        }
        
        stk.top()->next=temp;
        return head;
        
    }
};
