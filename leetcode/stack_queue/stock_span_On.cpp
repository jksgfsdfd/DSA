class StockSpanner {
public:
    vector<pair<int,int>> array;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int count=1;
        while(array.size()!=0 and array.back().first<=price){
            count+=array.back().second;
            array.pop_back();
        }
        array.push_back({price,count});
        
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
