class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        set<string> s;
        map<string, int> vis;
        for(auto it: wordList) {s.insert(it); vis[it]=0;}
        
        if(s.find(endWord)==s.end()) return 0;
        
        queue<string> q;
        q.push(beginWord);
        int ans=1;
        
        while(!q.empty()){
            int sz= q.size();
            ans++;
            
            while(sz--){
                string cur= q.front();
                q.pop();
                
                for(int i=0;i<cur.size();i++){
                    for(int j=0;j<26;j++){
                        string neww= cur.substr(0,i) ;
                        neww.push_back(j+'a');
                        neww+= cur.substr(i+1);
                        
                        if(cur!=neww && s.find(neww)!=s.end() && vis[neww]==0){
                            vis[neww]=1;
                            q.push(neww);
                            if(neww==endWord) return ans;
                        }
                    }
                }
            }
        }
        
        return 0;     
        
    }
};