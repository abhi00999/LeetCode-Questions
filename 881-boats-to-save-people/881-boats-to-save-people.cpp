class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        multiset<int> m;
        for(auto it: people) m.insert(it);        
        int tot=0;
        
        while(m.size()){
            int top= *m.begin();
            m.erase(m.find(top));
            if(top==limit || m.size()==0) {tot++; continue;}
            auto it= m.lower_bound(limit-top);
            
            if(it!=m.end() && *it==limit-top){
                m.erase(m.find(limit-top));
                tot++;
                continue;
            }
            else{
                if(it!=m.begin())it--;                
                if(*it+top<=limit){m.erase(m.find(*it)); tot++;}
                else {m.erase(m.find(*it)); tot+=2;}
                continue;
            }
        }
        
        return tot;
    }
};