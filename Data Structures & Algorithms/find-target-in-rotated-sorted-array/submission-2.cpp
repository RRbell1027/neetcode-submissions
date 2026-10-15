class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size(), mid;
        int last = nums.back();
        while (left < right) {
            mid = left + (right - left) / 2;

            if (nums[mid] == target)
                return mid;

            // target in first part
            if (target <= last) {
                if (nums[mid] > last || nums[mid] < target)
                    left = mid + 1;
                else
                    right = mid;
            }

            // target in second part
            else {
                if (nums[mid] <= last || nums[mid] > target)
                    right = mid;
                else
                    left = mid + 1;
            }
        }
        return -1;
    }
};
