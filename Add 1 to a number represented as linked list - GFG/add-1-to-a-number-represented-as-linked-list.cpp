// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

Node* reverse(Node *head){
    if(head==NULL || head->next==NULL) return head;
    
    Node *nxt= reverse(head->next);
    head->next->next=head;
    head->next=NULL;
    return nxt;
    
}

class Solution
{
    public:
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        Node *l1=reverse(head);
        // Node *tmp=l1;
        // while(tmp!=NULL) {cout<<tmp->data<<" "; tmp=tmp->next;}
        // cout<<'\n';
        Node *l2= new Node(1);
        Node* ans= new Node(0);
        Node* res= ans;
        int rem=0;
        // int rem=0;
        
        while(l1!=NULL || l2!=NULL || rem>0){
            int value=0;
            if(l1!=NULL){
                value+=l1->data;
                l1=l1->next;
            }
            if(l2!=NULL){
                value+=l2->data;
                l2=l2->next;
            }
            value+=rem;
            
            
            Node* cur= new Node(value%10);
            rem= (value)/10;
            ans->next=cur;
            ans=ans->next;           
            
        }
        return reverse(res->next);
    }
    
};

// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 
  // } Driver Code Ends