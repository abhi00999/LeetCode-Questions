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
        ListNode* ans= new ListNode(0);
        ListNode* res= ans;
        int rem=0;
        
        while(l1!=NULL || l2!=NULL || rem>0){
            int value=0;
            if(l1!=NULL){
                value+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL){
                value+=l2->val;
                l2=l2->next;
            }
            value+=rem;
            
            
            ListNode* cur= new ListNode(value%10);
            rem= (value)/10;
            ans->next=cur;
            ans=ans->next;           
            
        }
        return res->next;
    }
};