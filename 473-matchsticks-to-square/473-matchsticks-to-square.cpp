class Solution {
public:
    
    int ans;
    void f(int idx, int a, int b, int c, int d, int val, vector<int> &v){
        if(idx==v.size()){
            if(a==b && b==c && c==d && d==val) {ans=1;}
            return;
        }
        
        if(ans) return;
        if(a>val || b> val || c> val || d> val) return;
        f(idx+1, a+v[idx], b, c, d, val, v);
        f(idx+1, a, b+v[idx], c, d, val, v);
        f(idx+1, a, b, c+v[idx] , d, val, v);
        f(idx+1, a, b, c, d+v[idx], val, v);
        
    }
    bool makesquare(vector<int>& v) {
        sort(v.begin(), v.end(), greater<int>());
        int sum=0;
        for(auto it: v) sum+=it;
        
        if(sum%4) return false;
        
        ans=0;
        f(0, 0, 0, 0, 0, sum/4, v);
        
        return (ans==1);
    }
};