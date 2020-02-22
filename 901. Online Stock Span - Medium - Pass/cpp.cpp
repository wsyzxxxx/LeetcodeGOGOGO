class StockSpanner {
private:
    std::stack<std::pair<int, int> > stock;
public:
    StockSpanner() {
        while (!stock.empty()) {
            stock.pop();
        }
    }
    
    int next(int price) {
        int count = 1;
        while (!stock.empty() && stock.top().first <= price) {
            count += stock.top().second;
            stock.pop();
        }
        stock.push({price, count});
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
