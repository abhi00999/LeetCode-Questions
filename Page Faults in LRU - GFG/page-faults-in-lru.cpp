// { Driver Code Starts
// Initial Template for C++



#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int pageFaults(int n, int c, int pages[]){
        // code here
        unordered_set<int> s;
        unordered_map<int,int> mp;
        
        int pgfaults=0;
        for(int i=0;i<n;i++){
            
            // if size of cache is less than c
            if(s.size()<c){
                
                // if page is not found then insert it and also update its index
                if(s.find(pages[i])==s.end()){
                    pgfaults++;
                    s.insert(pages[i]);
                }
                
                // if page found then just update its index
                mp[pages[i]]=i;
            }
            
            else{
                
                // LRU algorithm : find least recently used using the index saved in the map
                if(s.find(pages[i])==s.end()){
                    pgfaults++;
                    int lru=INT_MAX;
                    int val;
                    
                    for(auto it: mp){
                        if(lru>it.second){
                            lru=it.second;
                            val=it.first;
                        }
                    }
                    
                    // Delete LRU from set and its corresponding (key, index) from map also
                    s.erase(val);
                    mp.erase(val);
                    // insert the new value
                    s.insert(pages[i]);
                }
                // update the index
                mp[pages[i]]=i;
            }
        }
        return pgfaults;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, C;
        cin>>N;
        int pages[N];
        for(int i = 0;i < N;i++)
            cin>>pages[i];
        cin>>C;
        
        Solution ob;
        cout<<ob.pageFaults(N, C, pages)<<"\n";
    }
    return 0;
}  // } Driver Code Ends