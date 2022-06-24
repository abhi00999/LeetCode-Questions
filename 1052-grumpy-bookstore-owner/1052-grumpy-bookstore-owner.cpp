class Solution {
public:
    int maxSatisfied(vector<int>& c, vector<int>& g, int min) {
        int maxi=0,res=0,cur=0;
        int n=c.size();
        
        for(int i=0;i<n;i++){
            if(g[i]==0) res+=c[i];
        }
        
        int i=0,j=0;
        while(j<n){
            if(j-i<min){
                if(g[j]==1){
                    cur+=c[j];
                }
                maxi= max(maxi,cur);
                j++;
            }
            
            else{
                maxi= max(maxi,cur);
                if(g[i]==1) cur-=c[i];
                i++;
                
                if(g[j]==1) cur+=c[j];
                maxi= max(maxi,cur);
                j++;
            }
        }
        
        return res+maxi;
    }
};