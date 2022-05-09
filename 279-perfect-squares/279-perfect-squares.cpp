class Solution {
public:
    int numSquares(int n) {
        vector<int> coins;
        
        for(int i=1;i*i<=10000;i++) coins.push_back(i*i);

		vector<int>res(n+1, INT_MAX);
        
        //zero can be made with zero coins
		res[0] = 0;
        
        for(int i=1;i<=n;i++){
            for(auto it: coins){
                if(i-it>=0 && res[i-it]!=INT_MAX){
                    res[i]=min(res[i],1+res[i-it]);
                }
            }
        }
        
        return res[n];
        
    }
};
