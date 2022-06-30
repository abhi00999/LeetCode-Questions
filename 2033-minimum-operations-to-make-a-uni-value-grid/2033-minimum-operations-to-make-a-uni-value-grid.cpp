class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> v;
        int ans=0;
        for(auto it: grid) for(auto it1: it) {v.push_back(it1);} 
        
        sort(v.begin(),v.end());
        if(v[0]==v[v.size()-1]) return 0;
        
        int rem= v[0]%x;
        for(auto it: v) if(it%x!=rem) return -1;
        
        int medianIndex= v.size()/2;
        
        for(int i=0;i<v.size();i++){
            if(i==medianIndex) continue;
            
            int diff= abs(v[medianIndex]-v[i]);
            ans+=diff/x;
        }
        return ans;
                                              
    }
};