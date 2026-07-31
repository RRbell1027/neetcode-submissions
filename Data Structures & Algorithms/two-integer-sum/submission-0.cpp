class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> table;
        for (int i = 0; i < nums.size(); i++) {
            int n = nums[i];
            if (table.find(n) == table.end()) {
                table[target - n] = i;
            } else {
                vector<int> vec = {table[n], i};
                return vec;
            }
        }
    }
};
