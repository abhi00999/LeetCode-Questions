/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        queue<Node*> q;
        
        q.push(root);
        
        while(!q.empty()){
            vector<Node*> v;
            
            int sz= q.size(),sz1=q.size();
            
            while(sz1--){
                Node* top= q.front();
                q.pop();
                v.push_back(top);
                if(top->left) q.push(top->left);
                if(top->right) q.push(top->right);
            }
            
            // for(auto it: v) cout<<it->val<<" ";
            // cout<<"\n";
            for(int i=0;i<sz-1;i++){
                v[i]->next= v[i+1];
            }
            v[sz-1]->next=NULL;
            
        }
        return root;
    }
};