#define pii               pair<long long,long long>
#define fi                first
#define se                second

class Solution {
public:
    vector<pair<int,int>> g[100001];
    vector<pair<int,int>> rev[100001];
    
    void dijk(long long src,vector<long long> &distTo){
        priority_queue<pii, vector<pii>, greater<pii> > pq;
        long long k=0;
        distTo[src]=k;
        
        pq.push(make_pair(k,src));
        
        while(!pq.empty()){
            long long dist=pq.top().first;
            long long prev=pq.top().second;
            
            pq.pop();
            for(auto it: g[prev]){
                long long next=it.first;
                long long nextDist= it.second;
                
                if(distTo[next]>distTo[prev]+nextDist){
                    distTo[next]=distTo[prev]+nextDist;
                    pq.push(make_pair(distTo[next],next));
                }
            }
        }
    }
    void dijk1(long long src,vector<long long> &distTo){
        priority_queue<pii, vector<pii>, greater<pii> > pq;
        long long k=0;
        distTo[src]=k;
        
        pq.push(make_pair(k,src));
        
        while(!pq.empty()){
            long long dist=pq.top().first;
            long long prev=pq.top().second;
            
            pq.pop();
            for(auto it: rev[prev]){
                long long next=it.first;
                long long nextDist= it.second;
                
                if(distTo[next]>distTo[prev]+nextDist){
                    distTo[next]=distTo[prev]+nextDist;
                    pq.push(make_pair(distTo[next],next));
                }
            }
        }
    }
    
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        long long ans=1e17,x=0,y=0,xx=0,yy=0;
        map<pair<int,int>,int>m;
        for(auto it: edges){
            if(m.find({it[0],it[1]})== m.end()) m[{it[0],it[1]}]= it[2];
            else m[{it[0],it[1]}]= min(it[2], m[{it[0],it[1]}]);
            // maxi= max(it[0],it[1]);
        }
        for(int i=0;i<1e5+1;i++) g[i].clear(), rev[i].clear();
        for(auto it: m){
            g[it.first.first].push_back({it.first.second,it.second});
            rev[it.first.second].push_back({it.first.first,it.second});
        }  
        vector<long long> v1(1e5+2,1e15),v2(1e5+2,1e15),v3(1e5+2,1e15);
        dijk(src1,v1);
        dijk(src2,v2);
        dijk1(dest,v3);
        
        for(int i=0;i<1e5+1;i++) ans= min(ans, v1[i]+v2[i]+v3[i]);
        
        if(ans>1e12) return -1;
        return ans;
        
    }
};