class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // filter
        unordered_map<char, vector<vector<int>>> nums;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                if (c == '.')
                    continue;
                if (nums.contains(c)) {
                    nums[c].push_back({i, j});
                } else {
                    nums[c] = {{i, j}};
                }
            }
        }

        // raw/column check
        vector<int> trans = {0, 0, 0, 1, 1, 1, 2, 2, 2};
        for (auto [c, pos]: nums) {
            vector<int> raw(9, 0);
            vector<int> col(9, 0);
            vector<vector<int>> box = {{0, 0, 0},{0, 0, 0},{0, 0, 0}};
            for (auto p: pos) {
                if (raw[p[0]]++ != 0)
                    return false;
                if (col[p[1]]++ != 0)
                    return false;
                if (box[trans[p[0]]][trans[p[1]]]++ != 0)
                    return false;
            }
        }
        return true;
    }
};
