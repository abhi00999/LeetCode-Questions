class Solution {
public:
    int distributeCookies(vector<int>& a, int k) {
        int l=0,h=0,n=a.size(),ans=INT_MAX;
        for(int i=0;i<n;i++) h+=a[i];
        ans=h;
        while(l<=h)
        {
            int mid=(l+h)/2,t2=0;
            int q=1;
            for(int i=1;i<=n;i++) q*=i;
            while(q--)
            {
                int t1=0,c=a[0],z=1;
                for(int i=1;i<n;i++)
                {
                if(a[i]>mid) t1++;
                if(a[i]+c<=mid) c+=a[i];
                else { c=a[i], z++; }
                }
                
                
                if(z<=k && a[0]<=mid && t1==0) { t2++;break; }
                next_permutation(a.begin(),a.end());
            }
            
            
            if(t2>0) { ans=min(ans,mid); h=mid-1;  }
            else l=mid+1;
        }
        return ans;
    }
};