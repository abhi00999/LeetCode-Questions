// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
 private:
  long long merge(long long *arr, long long *temp, long long l, long long mid, long long r){
      long long i,j,k;
      long long inv_cnt = 0;
      
      i = l;
      j = mid;
      k = l;
      
      while((i <= mid - 1) && (j<=r)){
          if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];}
          else{
              temp[k++] = arr[j++];
              
              inv_cnt += (mid - i);
          }
      }
      
      while(i<=mid-1){
        temp[k++] = arr[i++];}
        
      while(j<=r){
        temp[k++] = arr[j++];}
    
        for(int i = l; i<=r;i++){
            arr[i] = temp[i];}
        
        return inv_cnt;
      
  }
  long long mergeSort(long long *arr, long long *temp, long long l, long long r){
      long long mid;
      long long inv_cnt = 0;
      
      if(r>l){
          mid = (l+r)/2;
          inv_cnt += mergeSort(arr,temp,l, mid);
          inv_cnt += mergeSort(arr,temp,mid+1,r);
          
          inv_cnt += merge(arr,temp,l,mid+1,r);
      }
      return inv_cnt;
  }
  public:
    long long int inversionCount(long long arr[], long long N)
    {
        long long temp[N];
        long long ans = mergeSort(arr,temp,0,N-1);
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends