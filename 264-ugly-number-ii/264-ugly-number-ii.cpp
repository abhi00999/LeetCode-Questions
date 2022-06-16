#define ll long long 
class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<ll, vector<ll>, greater<ll> > pq;
        map<long long int,int> m;
        long long a=2, b=3, c=5;
        pq.push(1);
        m[1]=1;
        
        while(n--){
            int top= pq.top();
            if(n==0) return top;
            pq.pop();
            if(m.count(top*a)==0)pq.push(top*a), m[top*a]=1;
            if(m.count(top*b)==0)pq.push(top*b), m[top*b]=1;
            if(m.count(top*c)==0)pq.push(top*c), m[top*c]=1;
        }
        
        return -1;
    }
};