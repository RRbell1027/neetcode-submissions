class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int left = 0;
        int right = n - 1;
        int ans = 0;
        while (left < right) {
            ans = max(ans, min(heights[left], heights[right]) * (right - left));
            if (heights[left] < heights[right]) {
                while (left < right && heights[left] < heights[right]) {
                    left++;
                    ans = max(ans, min(heights[left], heights[right]) * (right - left));
                }
            }
            else {
                if (heights[right] == heights[left]) {
                    right--;
                }
                while (left < right && heights[right] < heights[left]) {
                    right--;
                    ans = max(ans, min(heights[left], heights[right]) * (right - left));
                }
            }
        }
        return ans;
    }
};
