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
    ListNode* partition(ListNode* head, int x) {
        ListNode *tmp= new ListNode(0), *tmp1= new ListNode(0),*dummy,*dummy1;
        dummy=tmp;
        dummy1=tmp1;
        while(head!=NULL){
            if(head->val<x){
                ListNode *cur= new ListNode(head->val);
                tmp->next=cur;
                tmp=tmp->next;
            }
            else{
                ListNode *cur= new ListNode(head->val);
                tmp1->next=cur;
                tmp1=tmp1->next;
            }
            head=head->next;
        }
        tmp->next=dummy1->next;
        return dummy->next;                 
    }
};