class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int ans=target[0], last=target[0];
        
        for(int i=1;i<target.size();i++){
            if(target[i]<=last){
                last=target[i];
            }
            else{
                ans+= target[i]-last;
                last=target[i];
            }
        }
        
        return ans;
    }
};