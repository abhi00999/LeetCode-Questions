class Solution {
public:
    
    string calc(string s){
        vector<pair<int,char>> v;
        int cnt=1;
        string res;
        for(int i=1;i<s.size();i++){
            if(s[i]==s[i-1]) cnt++;
            else{
                v.push_back({cnt,s[i-1]});
                cnt=1;
            }
        }
        v.push_back({cnt,s[s.size()-1]});
        
        for(auto it: v){
            string cur= to_string(it.first),cur2;
            cur2.push_back(it.second);
            res+=cur;
            res+=cur2;
        }
        return res;
    }
    
    string countAndSay(int n) {
        if(n==1) return "1";
        string st="1";
        
        while(n>1){
            st= calc(st);
            n--;
        }
        return st;
    }
    
};