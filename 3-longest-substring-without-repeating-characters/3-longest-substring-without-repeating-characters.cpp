class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size(),res=0;
        if(n==1) return 1;
        map<char,int> m;
        
        int i=0,j=0;
        
        while(j<n){
            if(m[s[j]]<1){
                m[s[j]]++;
                j++;
            }
            
            else{
                int cur= j-i;
                m[s[i]]--;
                i++;
                res= max(res,cur);
            }
            
            if(j==n){
                res=max(res,j-i);
            }
        }
        
        return res;
    }
};