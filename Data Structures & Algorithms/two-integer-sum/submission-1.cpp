class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> table;
        for (int i = 0; i < nums.size(); i++) {
            int n = nums[i];
            if (table.contains(n))
                return {table[n], i};
            table[target - n] = i;
        }
        return {};
    }
};
