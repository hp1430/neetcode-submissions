class MedianFinder {
    priority_queue<int>pq;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        pq.push(num);
    }
    
    double findMedian() {
        int size;
        vector<int>temp;
        double ans;
        if(pq.size()%2==0) {
            size = (pq.size()/2)-1;
            while(size--) {
                temp.push_back(pq.top());
                pq.pop();
            }
            double first = pq.top();
            temp.push_back(pq.top());
            pq.pop();
            double second = pq.top();
            ans = (first+second)/2.0;
        }
        else {
            size = pq.size()/2;
            while(size--) {
                temp.push_back(pq.top());
                pq.pop();
            }
            ans = (double)(pq.top());
        }
        for(int i=0; i<temp.size(); i++) pq.push(temp[i]);
        return ans;
    }
};
