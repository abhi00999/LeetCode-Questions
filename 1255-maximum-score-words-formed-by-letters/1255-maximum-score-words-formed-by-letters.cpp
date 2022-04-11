class Solution {
public:
    int maxScoreWords(vector<string>& w, vector<char>& l, vector<int>& score) {
        int sz=w.size(),ans=0;
        map<char,int> m;
        for(auto it: l) m[it]++;
        
        for(int i=1;i< pow(2,sz); i++){
            int cur= i,j=0,val=0,flag=1;
            
            map<char,int> m1;
            while(cur>0){
                if(cur%2){
                    string s1= w[j];
                    for(auto it: s1) m1[it]++; 
                }
                cur/=2;
                j++;
                for(char x='a'; x<='z';x++) if(m1[x]>m[x]) {flag=0; break;}
                if(!flag) break;
            }
            
            if(flag){
                for(auto it: m1) val+= it.second* score[it.first-'a'];
                ans= max(ans,val);
            }
            
        }
        
        return ans;
    }
};