// first integer tells the current height the next two integers tell its coordinates
// see this--> https://www.youtube.com/watch?v=QvQiQcLCQ4Y
#define pii pair<int, pair<int, int> >
class Solution {
public:
    int trapRainWater(vector<vector<int>>& grid) {
        int R=grid.size(), C= grid[0].size();
        
        // So tat we dont visit already visited cell
        vector<vector<int> > vis(R, vector<int>(C,0));
        
        // Priority queue will help us track the minimum boundary
        priority_queue< pii , vector<pii> , greater<pii> > pq;
        
        int vol=0;
        
        // first of all we process the outer most boundary(outer most rows and columns)
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if(i==0 || i==R-1 || j==0 || j==C-1){
                    pq.push({grid[i][j], {i,j}});
                    vis[i][j]=1;
                }
            }
        }
        int minBdht=0;
        while(!pq.empty()){
            int currHt= pq.top().first;
            int r= pq.top().second.first, c= pq.top().second.second;
            pq.pop();
            
            minBdht= max(minBdht, currHt);
            int dr[]={1,0,0,-1};
            int dc[]={0,-1,1,0};
            
            // Exploring current cells neightbours
            for(int i=0;i<4;i++){
                int rr= r+dr[i], cc=c+dc[i];
                if(rr>=0 && rr<R && cc>=0 && cc<C && vis[rr][cc]==0){
                    pq.push({grid[rr][cc], {rr,cc}});
                    vis[rr][cc]=1;
                    
                    // For explanation see video from 14:00
                    if(grid[rr][cc]<minBdht){
                        vol+=minBdht-grid[rr][cc];
                    }
                }
            }
        }   
        
        return vol;
    }
};