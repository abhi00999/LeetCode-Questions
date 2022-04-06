// The idea is same with 3Sum, but need to care about combination of duplicates. Firstly sort A, then say we fix i as first number, and we want to find all possibilities of A[lo] + A[hi] == target - A[i]:
// Case1: A[lo] != A[hi]. Count the number of duplicates of A[lo] and A[hi], as cntlo and cnthi, then for i, there are cnthi*cntlo possibilities
// Case2: A[lo] == A[hi]. Now all number between lo and hi are same. Say the number of duplicates is n, any two of n can meet A[lo] + A[hi] == target - A[i], that is n*(n-1)/2.

class Solution {
public:
    int threeSumMulti(vector<int>& A, int target) {
        int n = A.size();
        sort(A.begin(), A.end());
        int ans = 0; 
        int mod = 1e9+7;
        for (int i=0; i<n-2; ++i) {
            int lo = i+1, hi = n-1;
            while (lo < hi) {
                if (A[i] + A[lo] + A[hi] == target) {
                    int cntlo=1, cnthi=1;
                    while (lo < hi && A[lo] == A[lo+1]) {cntlo++; lo++;}
                    while (lo < hi && A[hi] == A[hi-1]) {cnthi++; hi--;}
					// A[lo]==A[hi]
                    if (lo == hi) ans =(ans+cntlo*(cntlo-1)/2)%mod;
					// A[lo]!=A[hi]
                    else ans = (ans+cntlo*cnthi)%mod;
                    lo++; hi--; 
                } else if (A[i] + A[lo] + A[hi] > target) {
                    hi--;
                } else {
                    lo++;
                }
            }
            //cout << ans << endl;
        }
        return ans;
    }
};