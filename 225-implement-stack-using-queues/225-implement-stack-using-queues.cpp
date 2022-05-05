class MyStack {
public:
    
    queue<int> q;
    
    MyStack() {
        
    }
    
    void push(int x) {
        
        q.push(x);
        
    }
    
    int pop() {
        
        int ans;
        
        int i = 1;
        
        while(i<q.size()){
            
            int rem = q.front();
            q.pop();
            q.push(rem);
            
            i++;
        }
        
        ans = q.front();
        q.pop();
        
        return ans;
    }
    
    int top() {
        
        int ans;
        
        int i = 1;
        
        while(i<q.size()){
            
            int rem = q.front();
            q.pop();
            q.push(rem);
            
            i++;
        }
        
        ans = q.front();
        q.pop();
        q.push(ans);
        
        return ans;
        
    }
    
    bool empty() {
        
        return !q.size();
    }
};
/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */