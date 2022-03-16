// Solution1: Simulating
// Initialize am empty stack,
// iterate and push elements from pushed one by one.
// Each time, we'll try to pop the elements from as many as possibile popped.
// In the end, we we'll check if stack is empty.

class Solution {
    public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
            stack<int> stack;
            int i = 0;
            for (int x : pushed) {
                stack.push(x);
                while (stack.size() && stack.top() == popped[i]) {
                    stack.pop();
                    i++;
                }
            }
            return stack.size() == 0;
        }
};