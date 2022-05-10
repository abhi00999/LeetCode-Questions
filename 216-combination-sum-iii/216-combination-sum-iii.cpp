class Solution {
public:
    
    void calc(int ind, int k, int n, vector<vector<int>> &ans, vector<int> &v, vector<int> &options){
        if(n==0 && k==0){
            ans.push_back(v);
            return;
        }
        
        if(ind>=options.size() || k<0) return;
        
        if(options[ind]> n) return;
        
        v.push_back(options[ind]);
        
        calc(ind+1, k-1, n-options[ind], ans, v, options);
        
        v.pop_back();
        
        calc(ind+1, k, n, ans, v, options);
        return;
        
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> options;
        for(int i=1;i<10;i++) options.push_back(i);
        
        vector<vector<int>> ans;
        vector<int> v;
        calc(0,k,n,ans, v, options);
        return ans;
    }
};