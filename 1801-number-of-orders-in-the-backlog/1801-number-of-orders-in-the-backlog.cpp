class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        priority_queue<pair<int,int>, vector<pair<int,int>>> buy;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> sell;
        
        for(auto order : orders) {
            int price = order[0];
            int amount = order[1];
            int type = order[2];
            
            if(type == 0) {
                
                if(sell.size() > 0 and sell.top().first <= price) {
                    while(sell.size() > 0 and sell.top().first <= price and sell.top().second <= amount) {
                        amount -= sell.top().second;
                        sell.pop();
                    }
                    
                    if(amount > 0) {
                        if(sell.size() == 0)
                            buy.push({price,amount});
                        else if(sell.top().first <= price) {
                            auto temp = sell.top();
                            sell.pop();
                            sell.push({temp.first, temp.second - amount});
                        } else {
                            buy.push({price, amount});
                        }
                    }
                } else {
                    buy.push({price, amount});
                }
            } else {
                
                
                if(buy.size()>0 and buy.top().first >= price) {
                    while(buy.size() > 0 and buy.top().first >= price and buy.top().second <= amount) {
                        amount -= buy.top().second;
                        buy.pop();
                    }
                    if(amount > 0) {
                        if(buy.size() == 0) {
                            sell.push({price, amount});
                        } else if(buy.top().first >= price) {
                            auto temp = buy.top();
                            buy.pop();
                            buy.push({temp.first, temp.second - amount});
                        } else {
                            sell.push({price, amount});
                        }
                    }
                } else {
                    sell.push({price, amount});
                }
            }
        }
        
        int count = 0;
        int MOD = 1e9 + 7;
        
        while(buy.size() > 0) {
            count += buy.top().second;
            count %= MOD;
            buy.pop();
        }
        
        while(sell.size() > 0) {
            count += sell.top().second;
            count %= MOD;
            sell.pop();
        }
        
        return count;
    }
};