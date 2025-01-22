class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length(); // Initialize the length of the string
        map<char, int> freq; // To track the frequency of characters in the current window
        int ans = 0;         // To store the maximum length of a valid substring
        int mx = 0;          // Maximum frequency of a single character in the current window
        int l = 0;           // Left pointer of the window

        for (int r = 0; r < n; r++) { // Right pointer iterates over the string
            freq[s[r]]++;            // Increment frequency of the current character
            mx = max(mx, freq[s[r]]); // Update the maximum frequency in the current window

            // Check if the remaining characters can be replaced within k operations
            while ((r - l + 1) - mx > k) {
                freq[s[l]]--; // Shrink the window from the left
                l++;
            }

            // Update the maximum valid window length
            ans = max(ans, r - l + 1);
        }

        return ans; // Return the result
    }
};