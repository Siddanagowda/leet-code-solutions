class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        unordered_map<string, int> pattern_count;

        for (int i = 0; i < m; ++i) {
            string row_pattern = "";
            string flipped_pattern = "";

            for (int j = 0; j < n; ++j) {
                row_pattern += to_string(matrix[i][j]);
                flipped_pattern += to_string(1 - matrix[i][j]);
            }

            pattern_count[row_pattern]++;
            pattern_count[flipped_pattern]++;
        }

        int max_rows = 0;
        for (const auto& entry : pattern_count) {
            max_rows = max(max_rows, entry.second);
        }

        return max_rows;
    }
};