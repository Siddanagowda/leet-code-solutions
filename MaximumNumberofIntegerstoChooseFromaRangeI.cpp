class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> set(banned.begin(), banned.end());
        int cur_sum = 0;
        int count = 0;
        for (int i = 1; i <= n; i++) {
            if (set.find(i) == set.end()) {
                if (cur_sum + i <= maxSum) {
                    cur_sum += i;
                    count++;
                } else {
                    break;
                }
            }
        }
        return count;
    }
};