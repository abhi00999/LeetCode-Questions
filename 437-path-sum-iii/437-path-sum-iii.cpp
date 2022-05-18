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
//this is O(n) solution
// O(n) solution explanation--> https://www.youtube.com/watch?v=yyZA4v0x16w
class Solution {
public:
    int ans;
    void calc(TreeNode* root, map<long long, long long> &m, long long sum_till_now, long long targetSum){
        if(!root) return;
        int cur= sum_till_now+ root->val;
        
        if(m[cur-targetSum]) ans+= m[cur-targetSum];
        m[cur]++;
        
        calc(root->left, m, cur, targetSum );
        calc(root->right, m, cur, targetSum);
        m[cur]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        map<long long, long long> m;
        m[0]=1;
        ans=0;
        calc(root, m, 0, targetSum);
        return ans;

    }
};