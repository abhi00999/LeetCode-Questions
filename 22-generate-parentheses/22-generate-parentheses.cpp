class Solution {
public:
    
    bool check(string &s){
        int cnt=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') cnt++;
            
            else{
                if(cnt>0) cnt--;
                else return false;
            }
        }
        
        if(!cnt) return true;
        return false;
    }
    
    void f(string &s, int tot, vector<string> &res){
        if(s.size()==tot){
            if(check(s))res.push_back(s);
            return;
        }
        
        s.push_back('(');
        f(s, tot, res);
        s.pop_back();
        s.push_back(')');
        f(s, tot, res);
        s.pop_back();
        return;
    }
    
    vector<string> generateParenthesis(int n) {
        
        vector<string> res;
        string s;
        
        f(s,2*n,res);
        return res;
    }
};