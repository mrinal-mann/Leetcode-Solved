class Solution {
public:
    string longestPalindrome(string s) {
        string res = "";
        int reslen = 0;

        for (int i = 0; i < s.length(); i++) {
            // Odd-length palindrome
            int l = i, r = i;
            while (l >= 0 && r < s.length() && s[l] == s[r]) {
                if ((r - l + 1) > reslen) {
                    reslen = r - l + 1;
                    res = s.substr(l, reslen);
                }
                l--;
                r++;
            }

            // Even-length palindrome
            l = i;
            r = i + 1;
            while (l >= 0 && r < s.length() && s[l] == s[r]) {
                if ((r - l + 1) > reslen) {
                    reslen = r - l + 1;
                    res = s.substr(l, reslen);
                }
                l--;
                r++;
            }
        }

        return res;
    }
};
