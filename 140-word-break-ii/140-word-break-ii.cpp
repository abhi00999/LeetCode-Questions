// best solution(readable and all) is the 4ms solution(using unordered set)
class Solution {
public:
    void f(int ind, vector<string>& wordDict, string s, vector<string> &res, string &cur){
        if(ind==s.size()){
            cur.pop_back();
            res.push_back(cur);
            return;
        }
        
        string str="";
        for(int i=ind;i<s.size();i++){
            
            str.push_back(s[i]);
            //get every substring and check if it exists in vector
            if(find(wordDict.begin(),wordDict.end(),str) != wordDict.end()){
                //we have got a word in dict 
                //explore more and get other substrings
                string tmp= cur+str;
                tmp.push_back(' ');
                f(i+1,wordDict, s, res, tmp);
            }
        }
        
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        string cur="";
        vector<string> res;
        f(0,wordDict, s, res, cur);
        return res;
        
    }
};