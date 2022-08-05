class Solution {
public:
    map<pair<vector<int>, int>, int> m;
    
    int f(vector<int> &v, int t){
        if(t==0) return 1;
        if(t<0) return 0;
        
        if(m.count({v,t})) return m[{v,t}];
        
        int res=0;
        for(int i=0;i<v.size();i++){
            res+= f(v, t-v[i]);
        }
        return m[{v,t}]=res;
        
        
    }
    int combinationSum4(vector<int>& v, int target) {
        return f(v, target);
    }
};