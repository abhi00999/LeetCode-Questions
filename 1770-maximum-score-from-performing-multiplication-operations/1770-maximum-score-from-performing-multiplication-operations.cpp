// We can easy to realise that this is a Dynamic Programming problem. In operation ith, we can choose to pick the left or the right side of nums.
// The naive dp has 3 params which is dp(l, r, i), time complexity = O(m^3), l and r can be picked up to m numbers.
// We can optimize to 2 params which is dp(l, i), time complexity = O(m^2) , we can compute params r base on l and i:
// Where:
// l, r is the index of the left side and the right side corresponding.
// i is the number of elements that we picked.
// leftPicked: is the number of elements picked on the left side, leftPicked = l.
// rightPicked: is the number of elements picked on the right side, rightPicked = i - leftPicked = i - l.
// Finally: r = n - rightPicked - 1 = n - (i-l) - 1.
// Complexity

// Time: O(2 * m^2), where m <= 10^3
// Space: O(m^2)
class Solution {
public:
    int m, n;
    int memo[1000][1000];
    int maximumScore(vector<int>& nums, vector<int>& muls) {
        n = nums.size();
        m = muls.size();
        // initialising with -1 gives tle as there is a case with ans=-1 so we initialise with INT_MAX
        // memset(memo, -1, sizeof(memo));
        for(int i=0;i<1000;i++) for(int j=0;j<1000;j++) memo[i][j]=INT_MAX;
        return dp(0, 0, nums, muls);
    }
    int dp(int l, int i, vector<int>& nums, vector<int>& muls) {
        if (i == m) return 0; // Picked enough m elements
        if (memo[l][i] != INT_MAX) return memo[l][i];
        int pickLeft = dp(l+1, i+1, nums, muls) + nums[l] * muls[i]; // Pick the left side
        int pickRight = dp(l, i+1, nums, muls) + nums[n-(i-l)-1] * muls[i]; // Pick the right side
        return memo[l][i] = max(pickLeft, pickRight);
    }
};