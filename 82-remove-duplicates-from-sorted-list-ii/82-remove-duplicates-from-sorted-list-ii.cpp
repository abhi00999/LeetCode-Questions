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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy= new ListNode(0);
        ListNode* ans=dummy->next;
        ListNode* ini= head;
        
        //flag will become 1 when we find first non duplicate value;
        int flag=0;
        
        while(ini!=NULL){
            ListNode* tmp=ini;
            int cur=tmp->val,cnt=0;
            
            while(tmp!=NULL && tmp->val==cur){
                cnt++;
                tmp=tmp->next;
            }
            
            if(flag==0 && cnt==1){
                ans=ini;
                flag++;
            }
            
            // dry run below step if there is any confusion
            if(cnt==1) {dummy->next=ini; dummy=dummy->next; dummy->next=NULL;}
            
            ini=tmp;
            
        }
        
        return ans;
    }
};