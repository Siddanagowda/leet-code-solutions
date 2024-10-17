class Solution {
public:
    void backtrack(const string& digits, const vector<string>& phoneMap,
                   int index, string path, vector<string>& combinations) {
        if (index == digits.length()) {
            combinations.push_back(path);
            return;
        }
        string possibleLetters = phoneMap[digits[index] - '0'];
        for (char letter : possibleLetters) {
            backtrack(digits, phoneMap, index + 1, path + letter, combinations);
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }

        vector<string> phoneMap = {"",    "",    "abc",  "def", "ghi",
                                   "jkl", "mno", "pqrs", "tuv", "wxyz"};

        vector<string> combinations;
        backtrack(digits, phoneMap, 0, "", combinations);
        return combinations;
    }
};