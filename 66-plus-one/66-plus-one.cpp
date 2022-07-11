class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res;
        int rem=1,sum=0,i=digits.size()-1;
        
        while(i>=0 || rem>0){
            if(i>=0) sum+= digits[i]+rem;
            else sum+=rem;
            
            i--;
            res.push_back(sum%10);
            rem=sum/10;
            sum=0;
        }
        
        reverse(res.begin(),res.end());
        return res;
    }
};