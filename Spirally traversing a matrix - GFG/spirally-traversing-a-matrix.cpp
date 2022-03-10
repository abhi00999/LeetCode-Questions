// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        int le=0, ri=c-1, up=0,dw=r-1;
        vector<int> ans;
        int ver=0,hor=1,ii=0,jj=0;
        
        while(ans.size()<r*c){
            if(hor){
                if(ii%2==0){
                    for(int i=le;i<=ri;i++) ans.push_back(matrix[up][i]);
                    up++;
                }
                else{
                    for(int i=ri;i>=le;i--) ans.push_back(matrix[dw][i]);
                    dw--;
                }
                ii++;
            }
            
            if(ver){
                if(jj%2==0){
                    for(int i=up;i<=dw;i++) ans.push_back(matrix[i][ri]);
                    ri--;
                }
                else{
                    for(int i=dw;i>=up;i--) ans.push_back(matrix[i][le]);
                    le++;
                }
                jj++;
            }
            
            if(hor==0) hor=1; else hor=0;
            if(ver==0) ver=1; else ver=0;
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends