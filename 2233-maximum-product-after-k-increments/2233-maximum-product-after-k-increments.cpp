class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        long long prod=1,mod=1e9+7;
        
        multiset<int> m;
        for(auto it: nums) m.insert(it);
        
        while(k--){
            int top= *m.begin();
            m.erase(m.find(top));
            
            top++;
            m.insert(top);
        }
        
        for(auto it: m){
            prod*=it%mod;
            prod%=mod;
        }
        return prod%mod;
    }
};