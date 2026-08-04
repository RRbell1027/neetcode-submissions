class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int ans = 0, cur;
        for (int n: nums) {
            cur = 1;
            if (s.contains(n - 1)) continue;
            while (s.contains(++n))
                cur++;
            ans = max(ans, cur);
        }
        return ans;
    }
};
