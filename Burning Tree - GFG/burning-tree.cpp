// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    // tar stores address of target
    Node* tar;
    void dfs(Node* root, int t){
        if(root==NULL) return;
        
        if(root->data==t) {tar=root; return;}
        
        if(root->left) dfs(root->left, t);
        if(root->right) dfs(root->right, t);
    }
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        dfs(root, target);
        map<Node*, Node*> par;
        map<Node*, int> vis;
        
        queue<Node*> q;
        par[root]=NULL;
        q.push(root);
        
        // below bfs finds the parent of each node    
        while(!q.empty()){
            int sz=q.size();
            
            while(sz--){
                Node* top= q.front();
                q.pop();
                
                if(top->left){
                    par[top->left]=top;
                    q.push(top->left);
                }
                
                if(top->right){
                    par[top->right]=top;
                    q.push(top->right);
                }
            }
        }
        
        // Now we start burning the tree, from a node fire can go to three direction--> top(parent k paas), 
        // left child, right child
        q.push(tar);
        vis[tar]=1;
        int ans=-1;
        
        while(!q.empty()){
            int sz= q.size();
            
            while(sz--){
                Node* cur= q.front();
                q.pop();
                
                if(cur->left && vis[cur->left]==0){
                    q.push(cur->left);
                    vis[cur->left]=1;
                }
                if(cur->right && vis[cur->right]==0){
                    q.push(cur->right);
                    vis[cur->right]=1;
                }
                
                if(par[cur]!=NULL && vis[par[cur]]==0){
                    q.push(par[cur]);
                    vis[par[cur]]=1;
                }
                
            }
            ans++;
        }
        return ans;
        
        
    }
};

// { Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}
  // } Driver Code Ends