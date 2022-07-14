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
    map<int,int> m;
    
    TreeNode* calc(vector<int>& preorder, vector<int>& inorder,int pstart, int pend,int istart,int iend){
        if(istart>iend || pstart>pend) return NULL;
        
        TreeNode* cur=new TreeNode(preorder[pstart]);
        int st1=istart, en1=m[preorder[pstart]]-1;
        int st2=m[preorder[pstart]]+1,en2=iend;
        int x=m[preorder[pstart]]-istart;//this tells us by how big is our interval and so we adjust
        //our pstart and pend by this interval only
        
        cur->left=calc(preorder,inorder,pstart+1,pstart+x,st1,en1);
        cur->right=calc(preorder,inorder,pstart+x+1,pend,st2,en2);
        return cur;
        
        
    }
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size();
        m.clear();
        for(int i=0;i<n;i++) m[inorder[i]]=i;
        
        TreeNode* root= calc(preorder,inorder,0,n-1,0,n-1);
        return root;
    }
};