// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
   public:
   //Function to find the maximum number of meetings that can
   //be performed in a meeting room.
  // static bool mycam(int &a[],int &b[],)
  // {
  // return a[1]<b[1];}
     static bool mycamp(vector<int>&a,vector<int>&b)
   {
       return a[1]<b[1];
   }
   int maxMeetings(int start[], int end[], int n)
   {
     vector<vector<int>>act;
     for(int i=0;i<n;i++)
     act.push_back({start[i],end[i]});
     sort(act.begin(),act.end(),mycamp);
     int i=0,count=1;
     for(int j=1;j<n;j++)
     {
         if(act[i][1]<act[j][0])
         {
             count++;
             i=j;
         }
     }
     return count;
   }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends