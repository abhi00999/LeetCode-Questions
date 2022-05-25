// But it should also be apparent that if we were to define a subsequence of E that was the ideal nesting order of envelopes for the solution, then that array would be strictly increasing in both width and height.

// If we've already sorted E primarily by width, we should then be able to consider a corresponding array of just the heights and realize that the solution would be defined as the longest increasing subsequence of that.

// The only difficulty would be for consecutive envelopes with the same sorted width. To avoid that, we can simply make sure that our sort function sorts height in descending order so that the first envelope encountered for any given width would be the largest one.

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& E) {
        sort(E.begin(), E.end(), [](vector<int>& a, vector<int>& b) 
             -> bool {return a[0] == b[0] ? b[1] < a[1] : a[0] < b[0];});
        vector<int> dp;
        for (auto& env : E) {
            int height = env[1];
            int left = lower_bound(dp.begin(), dp.end(), height) - dp.begin();
            if (left == dp.size()) dp.push_back(height);
            
            //Variation of lis so we will have to keep changing by below step
            dp[left] = height;
        }
        return dp.size();
    }
};