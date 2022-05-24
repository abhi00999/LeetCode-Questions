// The key takeaway here for why we do k+1 iterations is that in the BF algorithm we typically run V-1 iterations since each ith iteration finds the minimum distance of length i from the src to each node and the maximum pathlength between two nodes is V-1 hence typically running V-1 iterations. Since we only want a path length of k+1, we simply have to just run k+1 iterations in the BF algo!
class Solution {
public:
    //bellman ford.
    //just run it k+1 iterations.
    int findCheapestPrice(int n, vector<vector<int>>& a, int src, int sink, int k) {
        
        vector<int> c(n, 1e8);
        c[src] = 0;
        
        for(int z=0; z<=k; z++){
            vector<int> C(c);
            for(auto e: a)
                C[e[1]] = min(C[e[1]], c[e[0]] + e[2]);
            c = C;
        }
        return c[sink] == 1e8 ? -1 : c[sink];
    }
};