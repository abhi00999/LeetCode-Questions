// { Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

 // } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    Node* construct(int in[], int pre[], int pstart, int pend, int istart, int iend, map<int,int> &m){
        if(pstart>pend || istart>iend) return NULL;
        
        Node* cur= new Node(pre[pstart]);
        int pos= m[pre[pstart]];
        
        int st1= istart, en1= pos-1;
        int st2= pos+1, en2= iend;
        
        int x= pos- istart;
        
        cur->left= construct(in, pre, pstart+1, pstart+x, st1, en1,m);
        cur->right= construct(in, pre, pstart+x+1, pend, st2,en2, m);
        
        return cur;
        
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        map<int,int> m;
        for(int i=0;i<n;i++) m[in[i]]=i;
        
        Node *root= construct(in, pre, 0, n-1, 0, n-1,m);
        return root;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}
  // } Driver Code Ends