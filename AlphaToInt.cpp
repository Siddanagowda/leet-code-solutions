class Solution {
public:
    string freqAlphabets(string s) {
        string result = "";
        int n = s.size();
        
        // Iterate from the back of the string
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '#') {
                // Handle two-digit numbers with '#'
                int num = stoi(s.substr(i - 2, 2)); // Extract two digits before '#'
                result += (char)('a' + num - 1);   // Convert to corresponding letter
                i -= 2;  // Skip the two-digit number and '#'
            } else {
                // Handle single-digit numbers
                result += (char)('a' + (s[i] - '1')); // Convert single digit to letter
            }
        }
        
        reverse(result.begin(), result.end()); // Reverse the result string to get the correct order
        return result;
    }
};
