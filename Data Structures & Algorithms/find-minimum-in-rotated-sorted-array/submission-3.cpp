class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        while (left < right) {
            if (nums[left] <= nums[right])
                return nums[left];

            int mid = left + (right - left) / 2;

            if (mid > 0 && nums[mid] < nums[mid - 1])
                return nums[mid];

            if (nums[mid] > nums[right])
                left = mid + 1;
            else
                right = mid;
        }

        return nums[left];
    }
};
