class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int> > res;
        sort(intervals.begin(),intervals.end());
        res.push_back(intervals[0]);
        int n=intervals.size();
        
        for(int i=1;i<n;i++){
            int cur= intervals[i][0];
            int last= res[res.size()-1][1], st= res[res.size()-1][0];
            
            if(cur<=last){
                res.pop_back();
                last= max(last, intervals[i][1]);
                res.push_back({st, last});
            }
            else res.push_back(intervals[i]);
            
        }
        
        return res;
    }
};