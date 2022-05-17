// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    
    void findTopoSort(int node, vector<int> &vis, vector<int> &st, vector<vector<int>> &adj ){
	    vis[node]=1;
	    for(auto it: adj[node]){
	        if(!vis[it]) findTopoSort(it,vis,st,adj);
	    }
	    st.push_back(node);
	}
    
    string findOrder(string dict[], int N, int K) {
        //code here
        string res;
        if(N==1){
            for(char x='a'; x<='a'+K;x++){
                res.push_back(x);
            }
            return res;
        }
        
        vector<vector<int>> adj(26);
        
        for(int i=0;i<N-1;i++){
            string cur= dict[i], next= dict[i+1];
            int j=0;
            
            while(j<cur.size() && j<next.size()){
                if(cur[j]==next[j]) {j++; continue;}
                else{
                    int x=cur[j]-'a',y=next[j]-'a';
                    adj[cur[j]-'a'].push_back(next[j]-'a');
                    break;
                }
            }
        }
        
        vector<int> vis(K,0);
	    vector<int> v;
	    
	    for(int i=0;i<K;i++){
	        if(!vis[i]) findTopoSort(i,vis,v,adj);
	    }
	    
	    reverse(v.begin(),v.end());
	   // if(v.size()==K){
	        for(auto it: v) res.push_back('a'+it);
	   // }
	   // else{
	   //     for(int i=0;i<K;i++) if(mm[i+'a']==0) v.push_back(i);
	   //     for(auto it: v) res.push_back('a'+it);
	   // }
	   // cout<<res<<"\n";
	    return res;
        
    }
};

// { Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends