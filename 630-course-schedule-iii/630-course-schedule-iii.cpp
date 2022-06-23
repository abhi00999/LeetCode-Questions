class Solution {
public:
    static bool cmp(vector<int> &x, vector<int> &y){
        return (x[1]<y[1]);
    }
    int scheduleCourse(vector<vector<int>>& v) {
        
        sort(v.begin(), v.end(), cmp);
        
        int st=0;
        priority_queue<int> pq;
        
        for(auto it: v){
            int curDuration= it[0], end=it[1];
            pq.push(curDuration);
            
            st+=curDuration;
            if(st>end){
                st-=pq.top();
                pq.pop();
            }
            
        }
        
        return pq.size();
        
        
    }
};