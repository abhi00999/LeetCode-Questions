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
            
            // suppose we have to find d(as that will be the old element) from this --> {a, b, c, a+b+c+d}
            // Now sum at this point is = 2*a+2*b+2*c+d
            // we subtract largest from sum(2*a+2*b+2*c+d -(a+b+c+d)) we get a+b+c
            // Now it is obvious that a+b+c<a+b+c+d, so if that is not the case we return false
             
            if(sum==0 || sum>=largest) return false;
            
            // we get d by doing this--> (a+b+c+d)%(a+b+c) {better than subtracting repeatedly}
            int old= largest%sum;
            
            // old wil be equal to zero only if sum=1(This is only possible if array has only 2 elements)
            if(sum!=1 && old==0) return false;
            
            pq.push(old);
            sum+=old;
            
        }
        
        return true;
    }
};