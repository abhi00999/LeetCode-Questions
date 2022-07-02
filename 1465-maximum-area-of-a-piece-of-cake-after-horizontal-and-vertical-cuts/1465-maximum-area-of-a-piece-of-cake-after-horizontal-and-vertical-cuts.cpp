class Solution {
public:
    int maxArea(int h, int w, vector<int>& hh, vector<int>& vv) {
        sort(hh.begin(),hh.end());
        sort(vv.begin(),vv.end());
        hh.push_back(h);
        hh.insert(hh.begin(),0);
        vv.push_back(w);
        vv.insert(vv.begin(),0);
        
        int maxh=0,maxw=0,mod=1e9+7;
        
        for(int i=1;i<hh.size();i++){
            
            maxh= max(maxh, hh[i]-hh[i-1]);
        }
        
        for(int i=1;i<vv.size();i++){
            maxw= max(maxw, vv[i]-vv[i-1]);
        }
        
        return (long)maxh * maxw % 1000000007;
    }
};