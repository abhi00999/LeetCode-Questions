class Solution {
public:
    void setZeroes(vector<vector<int>>& ma) {
      int m=ma.size();
        int n=ma[0].size();
        vector<int>row(m,-1);
        vector<int>col(n,-1);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(ma[i][j]==0)
                {
                    row[i]=1;
                    col[j]=1;
                }
            }
        }
     for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(row[i]!=-1)
                {
                    ma[i][j]=0;
                }
                if(col[j]!=-1)
                {
                    ma[i][j]=0;
                }
            }
        }
    }
};