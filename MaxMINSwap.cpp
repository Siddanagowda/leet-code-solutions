class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);  // Convert the number to a string
        int n = s.length();
        int last[10] = {0};  // To store the last occurrence of each digit (0-9)

        // Fill the last occurrence of each digit
        for (int i = 0; i < n; ++i) {
            last[s[i] - '0'] = i;
        }

        // Traverse each digit and check if there is a larger digit in the right
        for (int i = 0; i < n; ++i) {
            for (int d = 9; d > s[i] - '0'; --d) {
                if (last[d] > i) {  // If a larger digit exists later
                    swap(s[i], s[last[d]]);  // Swap current digit with that digit
                    return stoi(s);  // Convert string back to number and return
                }
            }
        }

        return num;  // If no swap can make the number larger, return original
    }
};
