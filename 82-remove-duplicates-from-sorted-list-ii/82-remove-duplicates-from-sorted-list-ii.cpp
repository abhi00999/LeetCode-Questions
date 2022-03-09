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
            // cout<<cnt<<' ';
            
            if(cnt==1) {dummy->next=ini; dummy=dummy->next; dummy->next=NULL;}
            // if(dummy!=NULL) cout<< dummy->val<<" ";
            
            ini=tmp;
            
        }
        
        return ans;
    }
};