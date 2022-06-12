class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        
        vector<unordered_set<string>> suffix(26);
        long long result = 0;
        
        for (auto& idea: ideas) {
            suffix[idea[0] - 'a'].insert(idea.substr(1));
        }
        
        
        for (int i = 0; i < 25; ++i) {
            for (int j = i + 1; j < 26; ++j) {
                
                // determine the intersection of two set.
                auto& setA = suffix[i];
                auto& setB = suffix[j];
                int interset = 0;
                for (auto& item: setA) {
                    interset += setB.count(item);
                }
                
                result += 2 * (setA.size() - interset) * (setB.size() - interset);
            }
        }
        
        return result;
    }
};