class MedianFinder {
    priority_queue<int> left_heap;
    priority_queue<int,vector<int>,greater<int>> right_heap;
    double median;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(num<this->median){
            this->left_heap.push(num);
        }else{
            this->right_heap.push(num);
        }
        if(left_heap.size()==right_heap.size()){
            this->median=(double(left_heap.top()+right_heap.top()))/2.00000;
        }else if(left_heap.size()==right_heap.size()+1){
            median=left_heap.top();
        }else if(left_heap.size()==right_heap.size()-1){
            median=right_heap.top();
        }else if(left_heap.size()==right_heap.size()+2){
            right_heap.push(left_heap.top());
            left_heap.pop();
            this->median=(double(left_heap.top()+right_heap.top()))/2.00000;
        }else if(left_heap.size()==right_heap.size()-2){
            left_heap.push(right_heap.top());
            right_heap.pop();
            this->median=(double(left_heap.top()+right_heap.top()))/2.00000;
        }
    }
    
    double findMedian() {
        return this->median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
