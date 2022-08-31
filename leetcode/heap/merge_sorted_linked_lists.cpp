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
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> next_ele_heap;
        ListNode* root_new;
        ListNode* iter_new;
        
        for(int i=0;i<lists.size();i++){
            ListNode* a=lists[i];
            if(a==NULL){
                lists.erase(lists.begin()+i);
                i--;
                continue;
            }
            next_ele_heap.push({a->val,i});
        }
        if(next_ele_heap.empty()){
            return root_new;
        }
        int idx_ele=next_ele_heap.top().second;
        root_new=lists[idx_ele];
        iter_new=root_new;
        next_ele_heap.pop();
        lists[idx_ele]=lists[idx_ele]->next;
        if(lists[idx_ele]!=NULL){
            next_ele_heap.push({lists[idx_ele]->val,idx_ele});
        }
        
        while(!next_ele_heap.empty()){
            idx_ele=next_ele_heap.top().second;
            next_ele_heap.pop();
            iter_new->next=lists[idx_ele];
            iter_new=iter_new->next;
            lists[idx_ele]=lists[idx_ele]->next;
            if(lists[idx_ele]==NULL){
                continue;
            }else{
                next_ele_heap.push({lists[idx_ele]->val,idx_ele});
            }
        }
        return root_new;
    }
};
