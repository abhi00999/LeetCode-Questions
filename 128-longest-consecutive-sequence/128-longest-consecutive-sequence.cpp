class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        map<int,int> m;
        for(auto it: nums) m[it]++;
        
        int maxi= 0;
        for(auto it: m){
            
            int cur= it.first, cnt=0;
            if(m.count(cur+1)==0){
                while(m.count(cur)){
                    cnt++;
                    cur--;
                }
            }
            maxi= max(cnt, maxi);
        }
        
        return maxi;            
    }
};