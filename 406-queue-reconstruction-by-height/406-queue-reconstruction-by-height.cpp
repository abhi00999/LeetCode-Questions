// Intuition :

// Sort the array in decreasing order of their heights and if two people have same height, sort them in increasing order of their [1] index. (We used compare function for this)
// [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]] => [[7,0], [7,1], [6,1], [5,0], [5,2], [4,4]]
// Now we constructed an array res which will have elements in order of sorted array at indexes based on the index of their [1] position.
// Now insert the elements according to the order in res
// [[7,0]] (insert [7,0] at index 0)
// [[7,0],[7,1]] (insert [7,1] at index 1)
// [[7,0],[6,1],[7,1]] (insert [6,1] at index 1)
// [[5,0],[7,0],[6,1],[7,1]] (insert [5,0] at index 0)
// [[5,0],[7,0],[5,2],[6,1],[7,1]] (insert [5,2] at index 2)
// [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]] (insert [4,4] at index 4)
// Time Complexity : O(N * N)
// Space Complexity : O(N)

class Solution {
public:
    static bool compare(vector<int> &a,vector<int> &b){
        if(a[0]==b[0]){
            return a[1]<b[1];
        }
        return a[0]>b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int> >& people) {
        int n=people.size();
        sort(people.begin(),people.end(),compare);
        vector<vector<int>> res;
        for(int i=0;i<n;i++){
            int idx=people[i][1];
            res.insert(res.begin()+idx,people[i]);
        }
        return res;
    }
};