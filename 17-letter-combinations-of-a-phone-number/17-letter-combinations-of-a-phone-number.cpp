class Solution {
public:
    vector<string> res;
    
    void calc(vector<vector<char>> &v, int i, int j, string cur,int n){
    
        
        if(cur.size()==n){
            res.push_back(cur);
            return;
        }
        
        if(i>=v.size()|| j>=v[i].size()) return;
        
        cur.push_back(v[i][j]);
        calc(v, i+1, 0, cur, n);
        cur.pop_back();
        
        calc(v,i,j+1, cur, n);
        
    }
    vector<string> letterCombinations(string digits) {
        int n=digits.size();
        res.clear();
        
        if(n==0) return {};
        map<char,vector<char> > m;
        m['2']={'a','b','c'};
        m['3']={'d','e','f'};
        m['4']={'g','h','i'};
        m['5']={'j','k','l'};
        m['6']={'m','n','o'};
        m['7']={'p','q','r','s'};
        m['8']={'t','u','v'};
        m['9']={'w','x','y','z'};
        
        vector<vector<char>> v;
        int j=0;
        while(j<digits.size()){
            vector<char> tmp= m[digits[j]];
            v.push_back(tmp);
            // for(auto it: tmp) cout<<it<<" ";
            // cout<<"\n";
            j++;
        }
        
        calc(v, 0, 0, "",n);
        
        return res;
    }
};