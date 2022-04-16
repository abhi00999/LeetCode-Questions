/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void giveVal(map<int,int> &m, TreeNode* root){
        if(root==NULL) return;
        
        root->val= m[root->val];
        giveVal(m, root->left);
        giveVal(m, root->right);
        
        return;
    }
    int calcSum(TreeNode* x, vector<int> &v){
        if(x==NULL) return 0;
        
        v.push_back(x->val);
        
        return x->val+ calcSum(x->left,v)+ calcSum(x->right, v);
    }
    TreeNode* convertBST(TreeNode* root) {
        if(root==NULL) return root;
        vector<int> v;
        
        int sum= calcSum(root, v);
        sort(v.begin(),v.end());
        map<int, int> m;
        m[v[0]]=sum;
        sum-=v[0];
        for(int i=1;i<v.size();i++){
            m[v[i]]=sum;
            sum-=v[i];
        }
        
        giveVal(m,root);
        return root;
    }
};