class Solution {
    vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int rows, cols, longest = 0;
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        rows = matrix.size();
        // Empty
        if(!rows) return 0;
        cols = matrix[0].size();
        // Matrix corresponding to Indegree count
        vector<vector<int>> Indegree(rows, vector<int>(cols));
        // Source nodes of increasing paths
        queue<pair<int, int>> q;
        
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                for(auto &d: directions){
                    int x = i + d[0];
                    int y = j + d[1];
                    // OUT OF BOUNDS CHECK
                    if(x >= 0 && x < rows && y >= 0 && y < cols){
                        // Increasing Path (end)
                        if(matrix[x][y] < matrix[i][j]) Indegree[i][j]++;
                    }
                }
                // Increasing Path (start)
                if(!Indegree[i][j]) q.push({i, j});
            }
        }
        // BFS
        while(!q.empty()){
            int size = q.size();
            while(size--){
                pair<int,int> current = q.front();    // Current matrix cell
                q.pop();
                // Explore neigbhors
                for(auto &d: directions){
                    int x = current.first + d[0];
                    int y = current.second + d[1];
                    // OUT OF BOUNDS CHECK
                    if(x >= 0 && x < rows && y >= 0 && y < cols){
                      // "Erase" current cell and move onto next level
                        if(matrix[x][y] > matrix[current.first][current.second] && --Indegree[x][y] == 0)
                            q.push({x,y});
                    }
                }
            }
            longest++;
        }
        return longest;
    }
};