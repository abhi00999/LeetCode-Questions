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
    vector<pair<int,int>> v;
    int totSum;
    int sumTillNode(TreeNode* root, map<TreeNode*, int> &m){        
        if(root==NULL) return 0;
        int right= sumTillNode(root->right, m);
        int left= sumTillNode(root->left, m);
        
        m[root]= left+right+root->val;
        return m[root];        
    }
    
    void f(TreeNode* root, map<TreeNode*, int> &m, int totSum){
        if(root==NULL) return;
        
        if(root->left !=NULL){
            int left= m[root->left];
            int rem= totSum-left;
            v.push_back({left,rem});
        }
        if(root->right !=NULL){
            int right= m[root->right];
            int rem= totSum-right;
            v.push_back({right,rem});
        }
        
        f(root->left,m, totSum);
        f(root->right,m, totSum);
        
    }
    int maxProduct(TreeNode* root) {
        
        v.clear();
        map<TreeNode*, int> m;
        sumTillNode(root,m);
        int totSum= m[root], mod=1e9+7;
        f(root,m,totSum);
        
        int idx, mini=INT_MAX;
        for(int i=0;i<v.size();i++){
            int diff= abs(v[i].first-v[i].second);
            if(diff<mini){
                mini=diff;
                idx=i;
            }
        }
        
        // for(auto it: v){
        //     cout<<it.first<<" "<<it.second<<'\n';
        // }
        return (long) v[idx].first*v[idx].second%mod;
    }
};