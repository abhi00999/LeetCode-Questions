class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0) return 0;
        map<char,int> m;
        int i=0,j=0,ans=1;
        
        while(j<s.size()){
            m[s[j]]++;
            if(m[s[j]]==1){
                ans= max(j-i+1, ans);
                // cout<<j-i+1<<' ';
                j++;
            }
            
            else{
                while(m[s[j]]>1){
                    m[s[i]]--;
                    i++;
                }
                ans= max(j-i+1, ans);
                j++;
            }
        }
        
        return ans;
    }
};