// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    bool check(int x, int y, int n, int m){
        if(x<0 || y<0 || x>=n || y>=m) return false;
        return true;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int ans=0,n=grid.size(),m=grid[0].size(),cnt=0;
        
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2) q.push({i,j});
                if(grid[i][j]==1) cnt++;
            }
        }
        
        int dx[]={1,0,0,-1};
        int dy[]={0,-1,1,0};
        
        while(!q.empty()){
            int sz=q.size();
            
            ans++;
            while(sz--){
                pair<int,int> pii= q.front();
                q.pop();
                int x=pii.first, y=pii.second;
                
                for(int i=0;i<4;i++){
                    if(check(x+dx[i], y+dy[i], n, m) && grid[x+dx[i]][y+dy[i]]==1){
                        q.push({x+dx[i], y+dy[i]});
                        grid[x+dx[i]][y+dy[i]]=2;
                        cnt--;
                    }
                }
            }
        }
        if(cnt==0) return ans-1;
        return -1;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends