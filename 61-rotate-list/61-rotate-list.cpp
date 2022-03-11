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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL) return head;
        
        ListNode* temp=head;
        ListNode* ans;
        int len=0;
        
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }
        k=k%len;
        if(k==0) return head;
        temp=head;
        
        while(temp!=NULL){
            if(temp->next==NULL){
                temp->next=head;
                break;
            }
            temp=temp->next;
        }
        
        len= len-k;
        int ch=0;
        temp=head;
        
        while(temp!=NULL){
            ch++;
            if(len==ch){
                ans= temp->next;
                temp->next=NULL;
            }
            temp= temp->next;
        }
        
        return ans;
        
    }
};