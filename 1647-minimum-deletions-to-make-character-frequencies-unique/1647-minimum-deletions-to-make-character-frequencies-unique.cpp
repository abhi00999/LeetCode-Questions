class Solution {
public:
    int minDeletions(string s) {
        map<int,int> m;
        multiset<int> s1;
        
        for(auto it: s) m[it]++;
        for(auto it: m) s1.insert(it.second);
        
        int ans=0;
        
        while(s1.size()>1){
            auto it= s1.rbegin();
            int val1=*it,val2;
            it++;
            val2=*it;
            
            if(val1==val2){
                ans++;
                s1.erase(s1.find(val1));
                if(val1-1>0)s1.insert(val1-1);
            }
            else s1.erase(val1);
        }
        
        return ans;
    }
};