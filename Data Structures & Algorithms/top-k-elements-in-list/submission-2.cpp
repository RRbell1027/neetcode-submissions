class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int n: nums) {
            mp[n]++;
        }

        priority_queue<pair<int, int>> maxheap;
        for (auto [n, c]: mp) {
            maxheap.push({c, n});
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
