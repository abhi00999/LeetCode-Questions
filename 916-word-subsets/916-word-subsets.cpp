class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        map<char, int> tot;
        vector<string> res;
        for(auto it: words2){
            map<char,int> m;
            
            for(auto i: it) m[i]++;
            for(auto i: m){
                tot[i.first]= max(i.second, tot[i.first]);
            }
        }
        
        for(auto it: words1){
            int flag=0;
            map<char,int> m1;
            for(auto i: it) m1[i]++;
            for(auto j: tot) if(j.second > m1[j.first]){flag=1; break;}
            if(flag==0) res.push_back(it);
        }
        return res;
    }
};