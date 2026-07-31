class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size());

        int left_product = 1;
        auto ans_it = ans.begin();
        for (auto it = nums.begin(); it != nums.end(); ++it, ++ans_it) {
            *ans_it = left_product;
            left_product *= *it;
        }


        int right_product = 1;
        auto ans_rit = ans.rbegin();
        for (auto it = nums.rbegin(); it != nums.rend(); ++it, ++ans_rit) {
            *ans_rit *= right_product;
            right_product *= *it;
        }

        return ans;
    }
};
