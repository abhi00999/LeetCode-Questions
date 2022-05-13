// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    int vis[10][10];
    
    bool check(int x,int y, int n){
        if(x<0|| x>=n || y<0 || y>=n) return false;
        return true;
    }
    
    void dfs(int x, int y, int dx[], int dy[],string cur, vector<vector<int> > &m, int n, vector<string> &res,string dir){
        // if(x<0|| x>=n || y<0 || y>=n) return;
        // cout<<x<<" "<<y<<"\n";
        if(m[x][y]==0 ) return;
        
        if(x==n-1 && y==n-1){
            res.push_back(cur);
            return;
        }
        
        vis[x][y]=1;
        int tmpx=x,tmpy=y;
        for(int i=0;i<4;i++){
            x=tmpx+dx[i];
            y=tmpy+dy[i];
            
            if(check(x,y,n) && vis[x][y]==0){
                cur.push_back(dir[i]);
                dfs(x,y,dx,dy,cur,m,n,res,dir);
                cur.pop_back();
                // vis[x][y]=0;
            }
            
        }
        vis[tmpx][tmpy]=0;
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> res;
        
        if(m[0][0]==0) return res;
        
        int dy[]={0,1,0,-1};
        int dx[]={-1,0,1,0};
        
        memset(vis,0, sizeof(vis));
        
        string cur="",dir="URDL";
        
        // vis[0][0]=1;
        dfs(0,0,dx,dy,cur,m,n,res,dir);
        
        return res;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends