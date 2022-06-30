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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *res= new ListNode(-5005);
        ListNode *tmp;
        tmp=res;
        while(head!=NULL){
            int curVal= head->val;
            ListNode* nxt= new ListNode(curVal);
            if(tmp->val<=curVal){
                tmp->next= nxt;
                tmp=tmp->next;
            }
            
            else{
                ListNode* st;
                st=res;
                while(st->next->val<curVal){
                    st=st->next;
                }
                ListNode* after=st->next;
                st->next=nxt;
                nxt->next=after;
                
            }
            head=head->next;
            // cout<<res->next->val<<' ';
        }
        
        
        return res->next;
    }
};