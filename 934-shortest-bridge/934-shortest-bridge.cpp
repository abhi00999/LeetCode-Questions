class Solution {
public:
    int dx[4]={1,0,0,-1};
    int dy[4]={0,-1,1,0};
    
    void dfs(int i, int j, int n, vector<vector<int>>& grid, vector<pair<int,int>> &q){
        if (min(i, j) >= 0 && max(i, j) < n && grid[i][j] == 1){
            grid[i][j]=2;
            q.push_back({i,j});

            for(int k=0;k<4;k++){
                dfs(i+dx[k], j+dy[k], n, grid, q);
            }
        }
        
    }
    int shortestBridge(vector<vector<int>>&A) {
        vector<pair<int, int>> q;
        int n= A.size();
        for (int i = 0; q.size() == 0 && i < A.size(); ++i)
            for (int j = 0; q.size() == 0 && j < A[0].size(); ++j)
                dfs(i, j, n, A, q);
        
        
        while (!q.empty()) {
            vector<pair<int, int>> q1;
            for (auto [i, j] : q) {
                for (int d = 0; d < 4; ++d) {
                    int x = i + dx[d], y = j + dy[d];
                    if (min(x, y) >= 0 && max(x, y) < A.size()) {
                        if (A[x][y] == 1)
                            return A[i][j] - 2;
                        if (A[x][y] == 0) {
                            A[x][y] = A[i][j] + 1;
                            q1.push_back({x, y});
                        }
                    }
                }
            }
            swap(q, q1);
        }
        
        return 0;
        
    }
};