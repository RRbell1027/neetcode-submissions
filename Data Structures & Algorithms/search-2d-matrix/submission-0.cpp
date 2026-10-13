class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int colsize = matrix[0].size();
        int left = 0, right = matrix.size() * colsize, mid, cur;
        while (left < right) {
            mid = left + (right - left) / 2;
            cur = matrix[mid / colsize][mid % colsize];
            if (cur == target)
                return true;
            else if (cur < target)
                left = mid + 1;
            else
                right = mid;
        }
        return false;
    }
};
