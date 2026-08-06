class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<pair<int, int>> st;
        vector<int> ans(n, 0);
        for (int i = 0;i < n; i++) {
            while (!st.empty() && st.back().first < temperatures[i]) {
                ans[st.back().second] = i - st.back().second;
                st.pop_back();
            }
            st.push_back({temperatures[i], i});
        }
        return ans;
    }
};
