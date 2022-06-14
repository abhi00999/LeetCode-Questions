class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n=h.size();
        stack<int> s,s1;
        
        vector<int> left(n),right(n);
        
//         to find left smaller than current index
        for(int i=0;i<n;i++){
            while(!s.empty() && h[s.top()]>=h[i]) s.pop();
            
            if(!s.empty()) left[i]=s.top()+1;
            else left[i]=0;
            
            s.push(i);
        }
//         to find right smaller than current index        
        for(int i=n-1;i>=0;i--){
            while(!s1.empty() && h[s1.top()]>=h[i]) s1.pop();
            
            if(!s1.empty()) right[i]=s1.top()-1;
            else right[i]=n-1;
            
            s1.push(i);
        }
        
        int ma=INT_MIN;
        for(int i=0;i<n;i++){
            int cur= (right[i]-left[i]+1)*h[i];
            ma= max(ma,cur);
        }
        return ma;
    }
};