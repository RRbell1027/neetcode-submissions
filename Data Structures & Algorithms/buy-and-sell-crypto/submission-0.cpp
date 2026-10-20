class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int maxprice = 0, res = 0;
        for (int i = n - 1; i >= 0; --i) {
            maxprice = max(maxprice, prices[i]);
            res = max(res, maxprice - prices[i]);
        }

        return res;
    }
};
