#include <vector>
#include <climits>


class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int min_price = INT_MAX;
        int max_profit = 0;

        for (int price : prices) {
            if (price < min_price) {
                min_price = price;
                continue;
            }

            if (price - min_price > max_profit) {
                max_profit = price - min_price;
            }
        }
        
        return max_profit;
    }
};
