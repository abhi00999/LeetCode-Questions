class Solution {
public:
    int threeSumClosest(vector<int>& num, int target) {
        std::sort(num.begin(), num.end());
        int maxi=INT_MAX,ans;
        
        for (int i = 0; i < num.size(); i++) {

            int tar = num[i]-target;
            int front = i + 1;
            int back = num.size() - 1;

            while (front < back) {

                int sum = num[front] + num[back]+tar;
                // int diff= abs(sum-target);
                if(abs(sum)<maxi){
                    maxi=abs(sum);
                    ans=sum+target;
                }
                
                if(sum>0) back--;
                else front++;
            }

        }
        
        return ans;
    }
};