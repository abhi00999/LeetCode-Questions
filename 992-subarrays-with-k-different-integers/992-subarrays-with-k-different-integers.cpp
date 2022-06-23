// Approach: To directly count the subarrays with exactly K different integers is hard but to find the count of subarrays with at most K different integers is easy. So the idea is to find the count of subarrays with at most K different integers, let it be C(K), and the count of subarrays with at most (K – 1) different integers, let it be C(K – 1) and finally take their difference, C(K) – C(K – 1) which is the required answer.

int atMostKDistinct(vector<int>& A,int n,int k){
    int count = 0;
    int left = 0;
    int right = 0;
    
    unordered_map<int,int> mp;
    
    while(right < n){
        
        //add current element in the map
        mp[A[right]]++;
        
        while(mp.size() > k){
            mp[A[left]]--;
            if(mp[A[left]] == 0){
                mp.erase(A[left]);
            }
            left++;
        }
        
        count += right-left+1;
        right++;
    }
    
    
    return count;
}


class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int k) {
        int n = A.size();
        // cout<<atMostKDistinct(A,n,k)<<" "<<atMostKDistinct(A,n,k-1)<<'\n';
        return atMostKDistinct(A,n,k) - atMostKDistinct(A,n,k-1);
    }
};