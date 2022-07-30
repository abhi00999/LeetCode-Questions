class Solution {
public:
    
    int f(string &s, char x, char y){
        int n=s.size(), pos=0,neg=0, maxi=0;
        int arr[n];
        int g=0;
        for(int i=0;i<n;i++){
            if(s[i]==x) arr[i]=1;
            else if(s[i]==y) arr[i]=-1 , g++;
            else arr[i]=0;
        }
        
        for(int i=0;i<n;i++){
            if(arr[i]==1) pos++;
            else if(arr[i]==-1) neg++ , g--;
            
            if(pos>=neg && pos && neg) maxi= max(maxi, pos-neg);
            // Below condition means ki aage negative hai aur abhi negative overpower kar 
            // rha positive ko toh aage wale negative ko hi consider karenge
            // par agr aage negative nai hy toh iss wale negative ko lena hi hoga
            // (eg "lripaa") if 'a'= pos && 'p'=neg then agr 'p' pe pohoche toh g 0 ho
            // jayega par kyuki aage 'p' nai hy toh iss wale 'p' ko lena hi hoga
            if(pos<neg&&g>0) {pos=0; neg=0;}
        }
        
        return maxi;
        
    }
    int largestVariance(string s) {
        
        int ans=0;
        map<char, int> m;
        for(auto it: s) m[it]=1;
        
        for(char x='a'; x<='z';x++){
            for(char y='a'; y<='z';y++){
                if(x==y) continue;
                else if(m[x] && m[y])ans= max(ans, f(s, x,y));
            }
        }
        
        return ans;
    }
};