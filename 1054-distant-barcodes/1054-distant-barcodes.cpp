class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& b) {
        int n=b.size();
        map<int,int> m;
        vector<int> res(n);
        vector<pair<int,int>> v;
        for(auto it: b) m[it]++;
        
        for(auto it: m) v.push_back({it.second,it.first});
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        int j=0;
        for(auto it: v){
            int val=it.first;
            while(val--){
                res[j]=it.second;
                j+=2;
                if(j>=n) j=1;
            }
            
        }
        return res;
    }
};