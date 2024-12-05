class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.length();

        int lCountStart = 0, rCountStart = 0;
        int lCountTarget = 0, rCountTarget = 0;

        for (int i = 0; i < n; i++) {
            if (start[i] == 'L')
                lCountStart++;
            if (start[i] == 'R')
                rCountStart++;
            if (target[i] == 'L')
                lCountTarget++;
            if (target[i] == 'R')
                rCountTarget++;
        }

        if (lCountStart != lCountTarget || rCountStart != rCountTarget) {
            return false;
        }

        int i = 0, j = 0;
        while (i < n && j < n) {
            while (i < n && start[i] == '_')
                i++;
            while (j < n && target[j] == '_')
                j++;

            if (i == n && j == n) {
                return true;
            }
            if (i == n || j == n) {
                return false;
            }
            if (start[i] != target[j]) {
                return false;
            }
            if (start[i] == 'L' && i < j) {
                return false;
            }
            if (start[i] == 'R' && i > j) { 
                return false;
            }
            i++;
            j++;
        }
        return true;
    }
};