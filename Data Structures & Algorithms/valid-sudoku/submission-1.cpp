class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9] = {0};
        int col[9] = {0};
        int box[9] = {0};
        int val;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                val = 1 << (board[i][j] - '1');
                if ((row[i] & val) != 0 || (col[j] & val) != 0||
                    (box[(i / 3) * 3 + j / 3] & val) != 0)
                    return false;
                row[i] |= val;
                col[j] |= val;
                box[(i / 3) * 3 + j / 3] |= val;
            }
        }
        return true;
    }
};
