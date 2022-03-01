// i&(i-1) drops the lowest set bit. For example: i = 14, its binary representation is 1110, so i-1 is 1101, i&(i-1) = 1100, the number of "1" in its binary representation decrease one, so ret[i] = ret[i&(i-1)] + 1. (Sorry, my English is so poor and I have tried my best to make it clearly, I hope you can understand my explanation)

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret(num+1, 0);
        for (int i = 1; i <= num; ++i)
            ret[i] = ret[i&(i-1)] + 1;
        return ret;
    }
};