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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        pair<int,ListNode*> size;
        if(lists.size()==0){
            return NULL;
        }
        if(lists.size()==1){
            return lists[0];
        }
        
        ListNode* list1;
        int i=0;
        for(;i<lists.size();i++){
            list1=lists[i];
            if(list1!=NULL){
                break;
            }
        }
        ListNode* list2;
        ListNode* root=list1;
        ListNode* newlist;
        for(++i;i<lists.size();i++){
            list2=lists[i];
            if(list2==NULL){
                continue;
            }
            //check for error
            if(list1->val<=list2->val){
                root=list1;
                newlist=root;
                list1=list1->next;
            }else{
                root=list2;
                newlist=root;
                list2=list2->next;
            }
            while(list1!=NULL and list2!=NULL){
                if(list1->val<=list2->val){
                    newlist->next=list1;
                    newlist=newlist->next;
                    list1=list1->next;
                }else{
                    newlist->next=list2;
                    newlist=newlist->next;
                    list2=list2->next;
                }
            }
            if(list1==NULL){
                while(list2!=NULL){
                    newlist->next=list2;
                    newlist=newlist->next;
                    list2=list2->next;
                }
            }
            
            if(list2==NULL){
                while(list1!=NULL){
                    newlist->next=list1;
                    newlist=newlist->next;
                    list1=list1->next;
                }
            }
            list1=root;
            
        }
        return root;
    }
};
