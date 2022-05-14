// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    void f(int ind, int sum, vector<int> &v , int tot, vector<int> &tmp, vector<vector<int>> &res){
        if(ind>=v.size() || sum> tot) return;
        
        if(sum==tot){
            res.push_back(tmp);
            return;
        }
        
        int cur=v[ind];
        sum+=v[ind];
        tmp.push_back(v[ind]);
        f(ind, sum, v, tot, tmp, res);
        
        sum-=v[ind];
        tmp.pop_back();
        
        //if the below while loop is not added then gives tle
        while(ind<v.size() && v[ind]==cur) ind++;
        f(ind,sum,v,tot, tmp, res);
    }
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        // Your code here
        vector<vector<int> > res;
        
        sort(A.begin(),A.end());
        vector<int> tmp;
        f(0,0,A,B,tmp,res);
        // return vector<vector<int>> (res.begin(),res.end());
        return res;
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	  // } Driver Code Ends