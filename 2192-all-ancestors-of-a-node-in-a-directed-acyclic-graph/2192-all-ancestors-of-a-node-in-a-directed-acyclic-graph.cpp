// Using simple BFS, we find every descendant of node `i` (Say `x`). `i` will be an ancestor of `x`.
//solution of some1 else
class Solution {
private:
    vector<vector<int>> res;
public:
    void bfs(vector<vector<int>>& graph, int i) {
        queue<int> q;
        vector<bool> vis(graph.size(), false);
        
        q.push(i);
        vis[i] = true;
        
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            for(auto &x : graph[curr]) {
                if(!vis[x]) {
                    res[x].push_back(i);
                    q.push(x);
                    vis[x] = true;
                }
            }
        }
    }
    
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        res = vector<vector<int>>(n);
        for(auto &x : edges) {
            graph[x[0]].push_back(x[1]);
        }
        
        for(int i = 0; i<n; i++) {
            bfs(graph, i);
        }
        
        return res;
    }
};