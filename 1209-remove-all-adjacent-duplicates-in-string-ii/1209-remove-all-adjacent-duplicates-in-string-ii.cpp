class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char, int> > v;
        
        string res;
        
        for(auto it: s){
            if(v.empty() || v.back().first!=it) v.push_back({it,1});
            
            else v.back().second++;
            
            if(v.back().second==k) v.pop_back();
        }
        
        for (auto& p : v) res += string(p.second, p.first);

        return res;
    }
};