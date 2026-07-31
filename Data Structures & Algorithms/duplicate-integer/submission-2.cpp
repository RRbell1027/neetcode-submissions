class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> existed;
        for (int i = 0; i < nums.size(); i++) {
            int n = nums[i];
            if (existed.find(n) != existed.end())
                return true;
            else
                existed.insert(n);
        }
        return false;
    }
};