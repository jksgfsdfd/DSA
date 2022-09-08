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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head;
        
        if(list1==NULL){
            return list2;
        }
        
        if(list2==NULL){
            return list1;
        }
        
        //handle empty case
        if(list1->val<list2->val){
            head=list1;
            list1=list1->next;
        }else{
            head=list2;
            list2=list2->next;
        }
        ListNode* new_list;
        new_list=head;
        while(list1!=NULL and list2!=NULL){
            if(list1->val<list2->val){
                new_list->next=list1;
                new_list=new_list->next;
                list1=list1->next;
            }else{
                new_list->next=list2;
                new_list=new_list->next;
                list2=list2->next;
            }
        }
        
        if(list1==NULL){
            new_list->next=list2;
        }
        
        if(list2==NULL){
            new_list->next=list1;
        }
        
        return head;
    }
};
