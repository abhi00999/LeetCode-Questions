// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




 // } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

// O(N) time and O(1) space
// find length
// reverse the second half of the LL
// compare with two pointers, one at the beginning and another at the middle
class Solution{
  public:
    //Function to check whether the list is palindrome.
    int FindLength(Node * head){
        int len = 0;
        while(head != NULL){
            head = head -> next;
            len++;
        }
        return len;
    }
    
    Node * ReverseUtil(Node * head){
        Node * prev = NULL, *curr = head;
        
        
        while(curr != NULL){
            Node* store = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = store;
        }
        
        return prev;
    }
    
    Node* ReverseLL(Node * head, int start){
        Node* prev = NULL, *curr = head;
        for(int i = 0; i < start; i++){
            prev = curr;
            curr = curr -> next;
        }
        prev -> next = ReverseUtil(curr);
        return prev -> next;
    }
    
    bool isPalindrome(Node *head)
    {
        //Your code here
        if(head -> next == NULL){
            return true;
        }
        
        int len = FindLength(head);
        Node* head2 = ReverseLL(head, (len+1)/2);
        
        
        Node* head1 = head;
        while(head2 != NULL){
            if(head2 -> data != head1 -> data){
                return false;
            }
            head1 = head1 -> next;
            head2 = head2 -> next;
        }
        return true;
    }
};


// { Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}

  // } Driver Code Ends