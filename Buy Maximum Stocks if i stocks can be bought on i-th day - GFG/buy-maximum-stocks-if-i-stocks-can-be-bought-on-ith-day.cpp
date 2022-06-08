// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    
    static bool comp(pair<int,int> &p1, pair<int,int> &p2){
        if(p1.first!=p2.first) return p1.first<p2.first;
        
        return p2.second>p1.second;
    }
    
    int buyMaximumProducts(int n, int k, int price[]){
        //Write your code here
        vector<pair<int,int> > v;
        for(int i=0;i<n;i++){
            v.push_back({price[i], i+1});
        }
        
        sort(v.begin(), v.end(), comp);
        int ans=0;
        for(int i=0;i<n;i++){
            if(k>=v[i].first*v[i].second){
                ans+=v[i].second;
                k-=v[i].first*v[i].second;
            }
            else if(k>0){
                int val= k/v[i].first;
                ans+=val;
                k-= val*v[i].first;
            }
        }
        return ans;
    }
};


// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, k;
	    cin >> n >> k;
	    int price[n];
	    for(int i = 0 ; i < n; i++){
	        cin >> price[i];
	    }
	    Solution ob;
	    int ans = ob.buyMaximumProducts(n, k, price);
	    cout << ans<<endl;
	}
	return 0;
}
  // } Driver Code Ends