class Solution {
public:
    vector<vector<int> > adj;
    int maxi;
    
    // In this problem, we don't just have a BINARY tree, we actually have a graph, 
    // since a node in this graph not just have left child and right child, 
    // we should pick the TOP TWO max incoming path and concatenate them together (other than simply add left + right)
    int dfs(int ind, vector<vector<int> > &adj, set<int> &subtree, set<int> &vis){
        
        vis.insert(ind);
        int m1=0;
        int m2=0;
        
        for(auto it: adj[ind]){
            if(vis.find(it)==vis.end() && subtree.find(it)!=subtree.end()){
                int depth= dfs(it, adj, subtree, vis);
                if(depth > m1){
                    m2 = m1;
                    m1 = depth;
                }
                else if(depth > m2)
                    m2 = depth;
            }
        }
        
        maxi= max(maxi, m1+m2);
        return m1+1;
        
    }
    
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<int> res(n-1);
        adj.resize(n+1);
        
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        for(int i=0;i<(1<<n);i++){
            set<int> subtree;
            for(int j=0;j<n;j++){
                if(i&(1<<j)){ //this bit is 1, means this node is chosen 
                    subtree.insert(j+1); //cities numbered from 1 
                }
            }
            
            //now we need to evaluate if this subtree is valid
            // So, in first example if we take subtree {1,3} it will be invalid
            // but subtree {1,2,3} will be valid
            int edge_number = 0;
            for(auto e : edges ){
                if(subtree.find(e[0])!=subtree.end() && subtree.find(e[1])!=subtree.end())
                    edge_number++;
            }
            
            if(edge_number < 1 || subtree.size() != edge_number + 1 )
                continue; //not valid subtree
            
            //till here, we have a valid subtree, and we need to use DFS to get the max diameter
            set<int> visited;
            maxi = 0;
            
            // starting dfs from first element of set
            dfs(*subtree.begin(), adj, subtree, visited); 
            res[maxi - 1]++;
        }
        return res;
    }
};