class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> counter(2001);
        for (int n: nums) {
            counter[n + 1000]++;
        }

        priority_queue<pair<int, int>> maxheap;
        for (int i = 0; i < 2001; i++) {
            maxheap.push({counter[i], i - 1000});
        }
        
        vector<int> result(k);
        for (int i = 0; i < k; i++) {
            auto [c, n] = maxheap.top();
            result[i] = n;
            maxheap.pop();
        }

        return result;
    }
};
