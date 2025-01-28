class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length(), m = t.length();
        int l = 0, r = 0, cnt = 0;
        int maxLen = INT_MAX;
        int sIndex = n;
        vector<int> hash(256, 0);

        for (char c : t) {
            hash[c]++;
        }

        while (r < n) {
            if (hash[s[r]] > 0)
                cnt++;
            hash[s[r]]--;
            while (cnt == m) {
                if (r - l + 1 < maxLen) {
                    maxLen = r - l + 1;
                    sIndex = l;
                }
                hash[s[l]]++;
                if (hash[s[l]] > 0)
                    cnt--;
                l++;
            }
            r++;
        }

        return maxLen == INT_MAX ? "" : s.substr(sIndex, maxLen);
    }
};