class Solution {
public:
    int sumSubseqWidths(vector<int>& A) {
        const long MOD = 1e9 + 7;
        int n = A.size();
        sort(A.begin(), A.end());

        long ans = 0;
        long powerOfTwo = 1; // This keeps track of 2^i % MOD

        for (int i = 0; i < n; ++i) {
            ans = (ans + (A[i] - A[n - i - 1]) * powerOfTwo) % MOD;
            powerOfTwo = (powerOfTwo * 2) % MOD;
        }

        return (ans + MOD) % MOD;
    }
};
