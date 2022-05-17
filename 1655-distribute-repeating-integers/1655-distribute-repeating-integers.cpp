// Given there are at most 50 unqiue values, and at most 10 customers.
// It's a sign that we could do a backtrack.
// The idea is to
// count the occurance of each number
// sort the customers' order quantities DESC
// do a backtrack with DFS on the nubmers that are enough to be distributed to customers


//why do we sort quantities in descending order
// imagine the counted quantity is [10, 15] and the wanted quantity is [5, 10, 10] (reversely [10, 10, 5])
// ascendingly sorted will result in first splitting the 10 -> 5+5 rem ==[5,15] rem ==[5, 5] -> fail with many dfs
// but descendingly it first splits 15 -> 10 + 5, resulting in remaining quantity [10, 5], then rem == [0, 5] then rem == [0, 0] with no wasted dfs
// This avoids many dfs that are likely to fail
class Solution {
public:
    bool res = false;
    
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int, int> conter;
        for (auto n : nums) {
            conter[n] += 1;
        }
		
        vector<int> counts;
        for (auto& e : conter) counts.push_back(e.second);
		
        sort(quantity.rbegin(), quantity.rend());
		
        dfs(quantity, counts, 0);
		
        return res;
    }
    
    void dfs(vector<int>& quantity, vector<int>& counts, int i) {
        if (i == quantity.size() || res) {
            res = true;
            return;
        }
		
        for (int j = 0; j < counts.size(); j++) {
            int n = counts[j];
			
            if (n >= quantity[i]) {
                counts[j] -= quantity[i];
                dfs(quantity, counts, i + 1);
                counts[j] += quantity[i];
            }
        }
    }
};