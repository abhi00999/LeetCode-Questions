class MedianFinder {
public:
    
    // p1 is max heap and stores first half of the array
    // p2 is min heap and stores second half of the array
    priority_queue <int> p1;
    priority_queue <int, vector<int>, greater<int> > p2;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(p1.empty() || (p1.top()>num)) p1.push(num); // if it belongs to the smaller half
        else p2.push(num); 
        
        // rebalance the two halfs to make sure the length difference is no larger than 1
        if(p1.size() > (p2.size()+1))
        {
            p2.push(p1.top());
            p1.pop();
        }
        else if(p1.size()+1<p2.size())
        {
            p1.push(p2.top());
            p2.pop();
        }
    }
    
    double findMedian() {
        if(p1.size() == p2.size()) return p1.empty()?0:( (p1.top()+p2.top())/2.0);
        else return (p1.size() > p2.size())? p1.top():p2.top(); 
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */