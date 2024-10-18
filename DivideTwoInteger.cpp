class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0) return INT_MAX;
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        if (dividend == INT_MIN && divisor == 1) return INT_MIN;

        long long ldividend = abs(static_cast<long long>(dividend));
        long long ldivisor = abs(static_cast<long long>(divisor));

        int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;
        long long quotient = 0;

        while (ldividend >= ldivisor) {
            long long temp = ldivisor;
            long long multiple = 1;
            while (ldividend >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }

            ldividend -= temp;
            quotient += multiple;
        }

        return sign * static_cast<int>(quotient);
    }
};
