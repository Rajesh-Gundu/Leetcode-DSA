class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int,vector<int>,greater<int>> minHeap;
    MedianFinder() {
        while(!minHeap.empty())
            minHeap.pop();
        while(!maxHeap.empty())
            maxHeap.pop();
    }
    
    void addNum(int num) {
        if(!minHeap.empty() && num > minHeap.top()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
            minHeap.push(num);
        }
        else {
            maxHeap.push(num);
        }
        if(maxHeap.size() - minHeap.size() > 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }
    
    double findMedian() {
        int n = minHeap.size() + maxHeap.size();
        if(n%2 == 1) {
            return (double)maxHeap.top();
        }
        return double((maxHeap.top()+minHeap.top())/2.0);
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */