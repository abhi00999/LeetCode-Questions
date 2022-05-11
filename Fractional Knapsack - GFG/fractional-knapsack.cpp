// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        vector<pair< double , pair< double, double> > > v;
        
        
        for(int i=0;i<n;i++){
            double unitVal= (arr[i].value*1.0) / (arr[i].weight);
            
            v.push_back({unitVal,{arr[i].value, arr[i].weight}});
        }
        
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        
        double w= 1.0*W,ans=0.0;
        for(auto it: v){
            double curWt= it.second.second,curVal= it.second.first;
            if(curWt<=w){
                w-=curWt;
                ans+=curVal;
            }
            
            else{
                ans+= it.first*w;
                w=0;
            }
        }
        return ans;
        
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends