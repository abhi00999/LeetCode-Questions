class Solution {
public:
    int longestSubstring(string s, int k) {
        int n=s.size();
        if(n<k) return 0;
        
        map<int,int> m;
        
        for(auto it: s) m[it]++;
        
        for(int i=0;i<n;i++){
            if(m[s[i]]<k){
                string s1= s.substr(0, i), s2= s.substr(i+1);
                return max(longestSubstring(s1,k), longestSubstring(s2,k));
            }
        }
        return s.size();
    }
};