// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};

void print(struct Node *Node)
{
    while (Node!=NULL)
    {
        cout << Node->data << " ";
        Node = Node->next;
    }
}

struct Node * mergeResult(struct Node *node1,struct Node *node2);

Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int nA;
        cin>>nA;
        int nB;
        cin>>nB;

        struct Node* headA=NULL;
        struct Node* tempA = headA;

        for(int i=0;i<nA;i++)
        {
            int ele;
            cin>>ele;
            if(headA==NULL)
            {
                headA=tempA=newNode(ele);

            }else{
                tempA->next = newNode(ele);
				tempA=tempA->next;
            }
        }

        struct Node* headB=NULL;
        struct Node* tempB = headB;


        for(int i=0;i<nB;i++)
        {
            int ele;
            cin>>ele;
            if(headB==NULL)
            {
                headB=tempB=newNode(ele);

            }else{
                tempB->next = newNode(ele);
				tempB=tempB->next;
            }
        }

        struct Node* result = mergeResult(headA,headB);

        print(result);
        cout<<endl;


    }
}
// } Driver Code Ends


/*

The structure of linked list is the following

struct Node
{
int data;
Node* next;
Node(int x) : data(x), next(nullptr) {}
};

*/

struct Node *reverse(Node *head){
    if(head->next==NULL ) return head;
    Node *nxt= reverse(head->next);
    head->next->next=head;
    head->next= NULL;
    return nxt;
}
struct Node * mergeResult(Node *node1,Node *node2)
{
    // your code goes here

    Node *tail=NULL, *ans=NULL;
    
    if(node1->data < node2->data)
   {
       ans = tail = node1;
       node1 = node1->next;
   }
   else
   {
       ans = tail = node2;
       node2 = node2->next;
   }
    
    while( node1 && node2){
        if(node1->data<node2->data){
            tail->next= node1;
            node1=node1->next;
        }
        else{
            tail->next=node2;
            node2=node2->next;
        }
        tail=tail->next;
    }
    
    tail->next= node1? node1: node2;
    return reverse(ans);
}