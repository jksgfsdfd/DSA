class StockSpanner {
public:
    vector<int> prices;
    StockSpanner() {
        
    }
    
    int next(int price) {
        this->prices.push_back(price);
        int size=this->prices.size();
        int count=0;
        for(int i=size-1;i>=0 and this->prices[i]<=price;i--){
            count++;
        }
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
