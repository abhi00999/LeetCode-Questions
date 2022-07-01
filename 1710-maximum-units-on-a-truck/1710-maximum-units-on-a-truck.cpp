class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b){
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& b, int truckSize) {
        sort(b.begin(),b.end(),cmp);
        int ans=0;
        for(auto it: b){
            if(it[0]<=truckSize){
                ans+= it[0]*it[1];
                truckSize-=it[0];
            }
            
            else{
                ans+= truckSize*it[1];
                truckSize=0;
                break;
            }
        }
        return ans;
    }
};