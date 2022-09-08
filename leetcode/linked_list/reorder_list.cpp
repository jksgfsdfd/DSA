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
    void reorderList(ListNode* head) {
        deque<ListNode*> q;
        while(head){
            q.push_back(head);
            head=head->next;
        }
        for(auto x:q){
            cout<<x->val<<endl;
        }
        if(!q.empty()){
            head=q.front();
            q.pop_front();
        }
        ListNode* explo=head;
        while(!q.empty()){
            cout<<explo->val<<endl;
            explo->next=q.back();
            q.pop_back();
            if(q.empty()){
                explo=explo->next;
                break;
            }
            explo=explo->next;
            explo->next=q.front();
            q.pop_front();
            explo=explo->next;
        }
        explo->next=NULL;
    }
};
