class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        map<int,int> t,b;
        int maxi1=INT_MIN,maxi2=INT_MIN,val1,val2;
        for(auto it: tops) {t[it]++; if(t[it]>maxi1) {maxi1=t[it]; val1=it;}}
        for(auto it: bottoms){b[it]++; if(b[it]>maxi2) {maxi2=b[it]; val2=it;}}
        
        int ans1=0,ans2=0;
        for(int i=0;i<tops.size();i++){
            if(tops[i]!=val1){
                if(bottoms[i]==val1) ans1++;
                else ans1=1e7;
            }
            
            if(bottoms[i]!=val2){
                if(tops[i]==val2) ans2++;
                else ans2=1e7;
            }
        }
        
        if(ans1>=1e7 && ans2>=1e7) return -1;
        else return min(ans1,ans2);
        
    }
};