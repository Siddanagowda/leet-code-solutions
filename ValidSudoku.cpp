class Solution {
public:
    
bool isValidSudoku(vector<vector<char>>& board) {
    vector<unordered_set<char>> rows(9);
    vector<unordered_set<char>> cols(9);
    vector<unordered_set<char>> boxes(9);

    for (int r = 0; r < 9; ++r) {
        for (int c = 0; c < 9; ++c) {
            char num = board[r][c];
            if (num == '.') {
                continue;
            }
            if (rows[r].count(num) || cols[c].count(num) || boxes[(r / 3) * 3 + (c / 3)].count(num)) {
                return false;
            }
            rows[r].insert(num);
            cols[c].insert(num);
            boxes[(r / 3) * 3 + (c / 3)].insert(num);
        }
    }
    return true;
}
};