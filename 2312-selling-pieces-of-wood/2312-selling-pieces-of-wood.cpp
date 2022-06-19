class Solution {
    long solve(int i, int j, map<pair<int, int>, long> &price, vector<vector<long>> &DP) {
        if (DP[i][j] != -1)
            return DP[i][j];
			
        // Check if we have a price for this sheet with height i and width j
        long ans = price.find(make_pair(i, j)) == price.end()? 0: price[make_pair(i, j)];
        
        for (int ii = 1; ii < i; ii++)
            ans = max(ans, solve(ii, j, price, DP) + solve(i - ii, j, price, DP)); // Cut the sheet horizontally and take the maximum
        
        for (int jj = 1; jj < j; jj++)
            ans = max(ans, solve(i, jj, price, DP) + solve(i, j - jj, price, DP)); // Cut the sheet virtically and take the maximum
        
        return DP[i][j] = ans;
    }
public:
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        map<pair<int, int>, long> price;
        for (vector<int> &vi: prices) price[make_pair(vi[0], vi[1])] = vi[2];
        vector<vector<long>> DP(m + 1, vector<long>(n + 1, -1));
        
        return solve(m, n, price, DP);
    }
};