// If we have a lot strings S1, S2, ... , Sk, where k is big number we want to find faster method. Let us create for each symbol sorted list of indexes for this symbol.

// Complexity, both time and space of preprocessing is O(n), we iterate once over our list.

// Complexity of one search for string S_i is O(m_i)*log(n), where m_i is length of string and we have log(n) factor, because we potentially can have list of indexes with length n. So if m is the longest length of S_i, we have complexity O(k m log n), when two-pointer approach has O(k n) complexity. So, if length of original string n is big and m is small, it is worth to use this method.
class Solution {
public:
    bool isSubsequence(string s, string t) {
        unordered_map<char, vector<int>> hash; //chars -> list of indices;
        for(int i=0; i<t.length();i++) hash[t[i]].push_back(i);
        
        int prev = -1;
        for(auto c : s){
            auto it = hash.find(c);
            if(it == hash.end()) return false;
            auto vec = it->second;
            int pos = upper_bound(vec.begin(), vec.end(), prev) - vec.begin(); // find the first pos whose value is greater than prev
            if(pos == vec.size()) return false;
            prev = vec[pos];
        }
        return true;
    }
};