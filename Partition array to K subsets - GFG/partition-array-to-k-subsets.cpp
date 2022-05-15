// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    bool check(int arr[], int tot, int k){
        
        for(int i=0;i<k;i++) if(arr[i]!=tot) return false;
        return true;
    }
    bool f(int ind, int a[], int n, int arr[], int k, int tot){
        if(ind==n){
            if(check(arr, tot, k)) return true;
            return false;
        }
        
        
        //didnt understant the optimization for if else in the below for loop
        //try again also see other approaches
        for(int i=0;i<k;i++){
            
            if(arr[i]>0){
                arr[i]+=a[ind];
                if(arr[i]<=tot && f(ind+1, a, n, arr, k, tot)) return true;
                arr[i]-=a[ind];
            }
            else{
                arr[i]+=a[ind];
                if(arr[i]<=tot && f(ind+1, a, n, arr, k, tot)) return true;
                arr[i]-=a[ind];
                break;
            }
        }
        
        return false;
    }
    
    
    bool isKPartitionPossible(int a[], int n, int k)
    {
         //Your code here
        int sum=0;
        for(int i=0;i<n;i++) sum+=a[i];
        int arr[k]={0};
        if(k>n || sum%k!=0)    return false;
        
        return f(0, a, n, arr, k, sum/k);
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	int k;
    	cin>>k;
    	Solution obj;
    	cout<<obj.isKPartitionPossible(a, n, k)<<endl;
    }
}  // } Driver Code Ends