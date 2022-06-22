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
            // we take the topmost element and that will be the current boundary height
            // as every other element will surely be greater than it
            int currHt= pq.top().first;
            int r= pq.top().second.first, c= pq.top().second.second;
            pq.pop();
            
            int dr[]={1,0,0,-1};
            int dc[]={0,-1,1,0};
            
            // Exploring current cell's neighbours
            for(int i=0;i<4;i++){
                int rr= r+dr[i], cc=c+dc[i];
                if(rr>=0 && rr<R && cc>=0 && cc<C && vis[rr][cc]==0){
                    
                    vis[rr][cc]=1;
                    
                
                    // water will only fill if the new cell has ht. less than that of current boundary height
                    // and ht. of water will be equal to currht itself so we push {currHt,{rr,cc}}
                    if(grid[rr][cc]<currHt){
                        vol+=currHt-grid[rr][cc];
                        pq.push({currHt, {rr,cc}});
                    }
                    
                    // otherwise we push as follows
                    else{
                        pq.push({grid[rr][cc], {rr,cc}});
                    }
                }
            }
        }   
        
        return vol;
    }
};