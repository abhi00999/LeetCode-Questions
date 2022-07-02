class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>res;
        int j=1;
        while(n>0){
            if(n==1){
                res.push_back(0);
                n--;
            }
            
            else{
                res.push_back(j);
                res.push_back(-1*j);
                n-=2;
                j++;
            }
        }
        return res;
    }
};