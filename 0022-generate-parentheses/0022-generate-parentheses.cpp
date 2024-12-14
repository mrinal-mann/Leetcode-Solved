class Solution {
public:
void dfs(int openP, int closeP, string s, int n, vector<string>& res) {
    // Base case: If the number of open and close parentheses are equal
    // and the total number of parentheses equals n * 2, add the current
    // string to the result vector.
    if (openP == closeP && openP + closeP == n * 2) {
        res.push_back(s);
        return;
    }

    // Recursive case: If we can still add an open parenthesis, do so.
    if (openP < n) {
        dfs(openP + 1, closeP, s + "(", n, res);
    }

    // Recursive case: If the number of close parentheses is less than the
    // number of open parentheses, add a close parenthesis.
    if (closeP < openP) {
        dfs(openP, closeP + 1, s + ")", n, res);
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> res; // To store all valid combinations of parentheses
    dfs(0, 0, "", n, res); // Start DFS with 0 open and close parentheses
    return res; // Return the resulting vector
}

};