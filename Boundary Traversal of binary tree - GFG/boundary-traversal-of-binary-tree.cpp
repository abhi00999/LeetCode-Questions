// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}









 // } Driver Code Ends
/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
public:
    
    void leaf(vector<int>&res, Node* root){
        if(!root) return;
        if(root->left==NULL && root->right==NULL) {res.push_back(root->data);}
        
        leaf(res, root->left);
        leaf(res, root->right);
    }
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int> res,res1,res2;
        if(!root) return res;
        res.push_back(root->data);
        auto it= root->left;
        auto it1=root->right;
        if(!it && !it1) return res;
        
        while(it!=NULL){
            if(it->left!=NULL || it->right!=NULL)res.push_back(it->data);
            if(it->left!=NULL)it=it->left;
            else it=it->right;
        }
        
        leaf(res1,root);
        for(int i=0;i<res1.size();i++) res.push_back(res1[i]);
        
        while(it1!=NULL){
            if(it1->left!=NULL || it1->right!=NULL)res2.push_back(it1->data);
            if(it1->right!=NULL)it1=it1->right;
            else it1=it1->left;
            
        }
        
        reverse(res2.begin(),res2.end());
        for(int i=0;i<res2.size();i++) res.push_back(res2[i]);
        
        return res;
        
    }
};

// { Driver Code Starts.

/* Driver program to test size function*/

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.boundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends