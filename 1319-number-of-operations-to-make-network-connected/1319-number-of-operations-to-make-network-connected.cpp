// Approach: for each connected component find extra connections in it
// extra connections = total connections - (minimum no. of connections)
// (minimum no. of connections)= no. of nodes - 1
// total connections= we traverse all vertices in a component, compute sum of sizes of their adjacency lists
// and total connection will be sum/2 (if not understanding then draw an example graph)
// Now if total no. of components= x, then extra wires required will be x-1
// So if extra Wires>=components-1 then ans=components-1


class Solution {
public:
    
    void dfs(int i, vector<int> &nodes, vector<int> &vis, vector<vector<int> > &adj){
        vis[i]=1;
        nodes.push_back(i);
        
        for(auto it: adj[i]){
            if(!vis[it]){
                dfs(it,nodes, vis, adj);
            }
        }
        
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<vector<int> > adj(n);
        
        for(auto it: connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int> vis(n,0);
        int components=0, extWires=0;
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                int sum=0;
                components++;
                vector<int> nodes;
                dfs(i,nodes,vis,adj);
                
                for(auto it: nodes){ sum+= adj[it].size();}
                if(nodes.size()>1)extWires+= sum/2 - (nodes.size()-1);
            }
            
        }
        if(extWires>=components-1) return components-1;
        return -1;
    }
};