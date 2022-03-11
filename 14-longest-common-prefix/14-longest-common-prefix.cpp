class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res;
        map<char,int> m;
        int st=0;
        
        for(int i=0;;i++){
            int ini,flag=0;
            
            if(i<strs[0].size()) ini= m[strs[0][i]];
            else break;
            
            for(int j=0;j<strs.size();j++){
                string cur= strs[j];
                if(i<cur.size()){
                    m[cur[i]]++;
                }
                else{flag=1; break;}
            }
            
            if(flag==1) break;
            if(m[strs[0][i]]-ini == strs.size()) res.push_back(strs[0][i]);
            else break;
        }
        
        return res;
        
        
        
    }
};