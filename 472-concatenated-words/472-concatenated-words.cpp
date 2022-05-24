class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> m(words.begin(),words.end());
        vector<string> ans;
        
        for(auto it: words){
            if(it==""){continue;}
            string cur= it;
            int sz= cur.size();
            vector<int> dp(sz+1,0);
            dp[0]=1;
            for(int i=1;i<=sz;i++){
                for(int j=0;j<i;j++){
                    if(dp[j]==1){
                        string p= cur.substr(j,i-j);
                        if(m.find(p)!=m.end() && p!=it) {dp[i]=1; break;}
                    }
                }
            }
            if(dp[sz]) ans.push_back(cur);
        }
        return ans;
    }
};