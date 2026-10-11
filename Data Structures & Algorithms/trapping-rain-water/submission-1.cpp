class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> prefix(n), suffix(n);
        
        int m = 0;
        for (int i = 0; i < n; i++) {
            m = max(m, height[i]);
            prefix[i] = m;
        }
        
        m = 0;
        for (int i = n - 1; i >= 0; i--) {
            m = max(m, height[i]);
            suffix[i] = m;
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            res += min(prefix[i], suffix[i]) - height[i];
        }
        return res;
    }
};
