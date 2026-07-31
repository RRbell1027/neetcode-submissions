class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> product(n), rproduct(n);
        product.front() = nums.front();
        rproduct.back() = nums.back();
        for (int i = 1; i < n; i++) {
            product[i] = product[i-1] * nums[i];
            rproduct[n - i - 1] = rproduct[n - i] * nums[n - i - 1];
        }

        vector<int> result(n);
        result[0] = rproduct[1];
        result[n-1] = product[n-2];
        for (int i = 1; i < n-1; i++) {
            result[i] = product[i-1] * rproduct[i+1];
        }

        return result;
    }
};
