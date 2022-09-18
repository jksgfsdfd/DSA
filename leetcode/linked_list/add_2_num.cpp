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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int extra=0;
        ListNode* prev=NULL;
        ListNode* curr;
        int val;
        
        ListNode* head;
        //initializing head
        val=l1->val+l2->val+extra;
        if(val>=10){
            extra=1;
            val=val%10;
        }else{
             extra=0;
        }
        curr = new ListNode(val);
        head=curr;
        prev=curr;
        l1=l1->next;
        l2=l2->next;
        
        
        while(l1 && l2){
            val=l1->val+l2->val+extra;
            if(val>=10){
                extra=1;
                val=val%10;
            }else{
                extra=0;
            }
            curr = new ListNode(val);
            prev->next=curr;
            prev=prev->next;
            l1=l1->next;
            l2=l2->next;
        }
        
        if(l1){
            while(l1){
                val=l1->val+extra;
                if(val>=10){
                    extra=1;
                    val=val%10;
                }else{
                    extra=0;
                }
                curr = new ListNode(val);
                prev->next=curr;
                prev=prev->next;
                l1=l1->next;
            }
        }
        
        if(l2){
            while(l2){
                val=l2->val+extra;
                if(val>=10){
                    extra=1;
                    val=val%10;
                }else{
                    extra=0;
                }
                curr = new ListNode(val);
                prev->next=curr;
                prev=prev->next;
                l2=l2->next;
            }
        }
        
        if(extra==1){
            curr = new ListNode(1);
            prev->next=curr;
            prev=prev->next;
        }
        
        curr->next=NULL;
        return head;
    }
};
