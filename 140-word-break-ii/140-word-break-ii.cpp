class Solution {
public:
    void f(int last, int cur_ind, vector<string>& wordDict, string s, vector<vector<string> > &res, vector<string> &cur, vector<bool> &dp){
        if(cur_ind==s.size()+1){
            res.push_back(cur);
            return;
        }
        
        for(int i=cur_ind;i<=s.size();i++){
            if(find(wordDict.begin(),wordDict.end(),s.substr(last, i-last)) != wordDict.end()){
                
                cur.push_back(s.substr(last, i-last));
                f(i,i+1,wordDict, s, res, cur, dp);
                cur.pop_back();
            }
        }
        
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size()+1,false);
        dp[0] = true;
        for(int i=0;i<=s.size();++i){
            for(int j=0;j<i;++j){
                if(dp[j])
                {
                    if(find(wordDict.begin(),wordDict.end(),s.substr(j,i-j)) != wordDict.end()){
                        dp[i] = true;
                        break;
                    }
                }
                
            }
        }
        // for(auto it: dp) cout<<it<<" ";
        // cout<<"\n";
        vector<vector<string>> res;
        vector<string> cur,ans;
        f(0,1,wordDict, s, res, cur, dp);
        
        for(auto it: res){
            string tmp="";
            for(auto it1: it){
                tmp+=" ";
                tmp+=it1;
            }
            if(tmp.size())tmp=tmp.substr(1);
            ans.push_back(tmp);
        }
        return ans;
        
    }
};