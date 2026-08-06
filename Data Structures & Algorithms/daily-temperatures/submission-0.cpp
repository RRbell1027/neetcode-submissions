class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<pair<int, int>> st;
        vector<int> ans(n);
        for (int i = 0;i < n; i++) {
            while (!st.empty() && st.back().first < temperatures[i]) {
                ans[st.back().second] = i - st.back().second;
                st.pop_back();
            }
            st.push_back({temperatures[i], i});
        }
        while (!st.empty()) {
            ans[st.back().second] = 0;
            st.pop_back();
        }
        return ans;
    }
};
