class Solution {
public:
    void helper(string digit, int index, string output, vector<string>& ans, string mapping[]) {
        if (index >= digit.length()) {
            ans.push_back(output);
            return;
        }
        int number = digit[index] - '0'; // Convert char digit to int
        string value = mapping[number]; // Get corresponding letters
        for (int i = 0; i < value.length(); i++) {
            output.push_back(value[i]);
            helper(digit, index + 1, output, ans, mapping);
            output.pop_back(); // Backtracking
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {}; // Handle empty input
        
        vector<string> ans;
        string output;
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        helper(digits, 0, output, ans, mapping);
        return ans;
    }
};
