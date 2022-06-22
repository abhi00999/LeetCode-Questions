// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&ini,vector<int>&fin,int N)
	{
	    // Code here
	    queue<pair<int,int> > q;
	    vector<vector<int> > vis(1001, vector<int> (1001, 0));
	    
	    vis[ini[0]][ini[1]]=1;
	    q.push({ini[0], ini[1]});
	    
	    int dx[]={-2, -2, -1, +1, +2, +2, +1, -1};
	    int dy[]={-1, +1, +2, +2, +1, -1, -2, -2};
	    int ans=0;
	    
	    while(!q.empty()){
	        int sz=q.size();
	        
	        while(sz--){
	            auto it= q.front();
	            int x=it.first, y=it.second;
	            q.pop();
	            if(x==fin[0] && y==fin[1]) return ans;
	            
	            for(int i=0;i<8;i++){
	                int xx= x+dx[i], yy= y+dy[i];
	                if(xx>=1 && xx<=N && yy>=1 && yy<=N && vis[xx][yy]==0){
	                    q.push({xx,yy});
	                    vis[xx][yy] =1;
	                }
	            }
	        }
	        ans++;
	        
	    }
	    return -1;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends