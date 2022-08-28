/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> set;
        ListNode* temp=head;
        while(temp!=NULL){
            if(set.find(temp)!=set.end()){
                return true;
            }else{
                set.insert(temp);
            }
            temp=temp->next;
        }
        return false;
    }
};