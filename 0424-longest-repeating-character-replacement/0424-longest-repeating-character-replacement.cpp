class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0, maxlen = 0, maxfre = 0;
        int hash[26] = {0}; // Array to store the frequency of characters
        
        while (r < s.size()) {
            hash[s[r] - 'A']++;
            maxfre = max(maxfre, hash[s[r] - 'A']);
            
            // Check if the window is valid
            if ((r - l + 1) - maxfre > k) {
                hash[s[l] - 'A']--;
                l++;
            }
            
            // Update the maximum length
            maxlen = max(maxlen, r - l + 1);
            r++;
        }
        
        return maxlen;
    }
};
