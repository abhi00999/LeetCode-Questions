// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void print(Node *root)
{
	Node *temp = root;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}
 

 // } Driver Code Ends
/*

The structure of linked list is the following
struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
*/

class Solution
{
    public:
    void swap(Node** ptr){
        int temp=(*ptr)->data;
        (*ptr)->data=(*ptr)->next->data;
        (*ptr)->next->data=temp;
    }
    Node *zigZag(Node* head)
    {
        // your code goes here
        if(head==NULL || head->next==NULL){
             return head;
        }
        bool flag=true;
        Node *temp=head, *tmp=head;
        while(temp->next!=NULL){
             if(flag==true){
                 if(temp->data>temp->next->data){
                     swap(&temp);
                 }
                 flag=false;
             }
             else{
                 if(temp->data<temp->next->data){
                     swap(&temp);
                 }
                 flag=true;
             }
             temp=temp->next;
            //  while(tmp!=NULL) {cout<<tmp->data<<' '; tmp=tmp->next;}
            //  cout<<"\n";
             tmp=head;
        }
        return head;
    }
};

// { Driver Code Starts.


int main() {
	// your code goes here
	int T;
	cin>>T;
	
	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;
 
		for(int i=0;i<K;i++){
		int data;
		cin>>data;
			if(head==NULL)
			head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp=temp->next;
			}
		}
		Solution ob;
		Node *ans = ob.zigZag(head);
		print(ans);
		cout<<endl;
	}
	return 0;
}  // } Driver Code Ends