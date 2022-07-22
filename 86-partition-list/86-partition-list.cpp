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
                tmp->next=head;
                tmp=tmp->next;
            }
            else{
                tmp1->next=head;
                tmp1=tmp1->next;
            }
            head=head->next;
        }
        tmp1->next=NULL;
        tmp->next=dummy1->next;
        return dummy->next;                 
    }
};