class Solution {
public:
    int numSquares(int n) {
        vector<int> coins;
        for(int i=1;i*i<=10000;i++) coins.push_back(i*i);

		vector<int>res(n+1, INT_MAX);

		res[0] = 0;
        int nn=coins.size();

		for (int i = 0; i < nn; i++) {
			for (int j =  coins[i]; j <= n; j++) {
				if (j>=coins[i] && res[j-coins[i]] != INT_MAX)
					res[j] = min(res[j], 1+res[j-coins[i]]);
			}
		}

		return res[n] != INT_MAX ? res[n] : -1;
    }
};
