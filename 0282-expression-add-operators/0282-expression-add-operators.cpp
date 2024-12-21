class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        string expr;
        solve(num, target, 0, 0, 0, expr, ans);
        return ans;
    }
    
    void solve(string &num, int target, int index, long currVal, long lastVal, string expr, vector<string> &ans) {
        if (index == num.size()) {
            if (currVal == target) {
                ans.push_back(expr);
            }
            return;
        }
        
        for (int i = index; i < num.size(); i++) {
            // Avoid leading zeros
            if (i > index && num[index] == '0') break;
            
            string part = num.substr(index, i - index + 1);
            long currNum = stol(part);
            
            if (index == 0) {
                // First number (no operator needed)
                solve(num, target, i + 1, currNum, currNum, part, ans);
            } else {
                // Add '+'
                solve(num, target, i + 1, currVal + currNum, currNum, expr + "+" + part, ans);
                // Add '-'
                solve(num, target, i + 1, currVal - currNum, -currNum, expr + "-" + part, ans);
                // Add '*'
                solve(num, target, i + 1, currVal - lastVal + lastVal * currNum, lastVal * currNum, expr + "*" + part, ans);
            }
        }
    }
};
