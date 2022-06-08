// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int c[], int n, int k)
    {
        // Write Your Code here
        sort(c,c+n);
        int left=0,right=n-1;
        int mini=0,maxi=0;
        
        while(left<=right){
            mini+=c[left];
            right-=k;
            left++;
        }
        
        left=0;
        right=n-1;
        while(left<=right){
            maxi+=c[right];
            left+=k;
            right--;
        }
        
        return {mini, maxi};
        
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}  // } Driver Code Ends