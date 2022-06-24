class Solution {
public:
    bool isPossible(vector<int>& target) {
        long int n=target.size(),sum=0;
        priority_queue<int>pq;
        
        for(auto it: target) pq.push(it), sum+=it;
        
        while(pq.top()!=1){
            int largest= pq.top();
            sum-=largest;
            
            pq.pop();
            
            if(sum==0 || sum>=largest) return false;
            
            int old= largest%sum;
            
            if(sum!=1 && old==0) return false;
            
            pq.push(old);
            sum+=old;
            
        }
        
        return true;
    }
};