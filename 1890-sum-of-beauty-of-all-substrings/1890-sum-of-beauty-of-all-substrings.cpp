class Solution {
public:
    int beautySum(string s) {
        int ans = 0; // Initialize the total beauty sum to 0

        // Outer loop to fix the starting point of the substring
        for (int i = 0; i < s.length(); i++) {
            map<char, int> mpp; // Map to store the frequency of characters in the current substring
            
            // Inner loop to extend the substring from the starting point 'i'
            for (int j = i; j < s.length(); j++) {
                mpp[s[j]]++; // Add the current character to the frequency map
                
                int leastfreq = INT_MAX; // Variable to track the least frequency in the current substring
                int maxfreq = INT_MIN;  // Variable to track the max frequency in the current substring
                
                // Traverse the frequency map to find the max and min frequencies
                for (auto it : mpp) {
                    leastfreq = min(leastfreq, it.second); // Update least frequency
                    maxfreq = max(maxfreq, it.second);    // Update max frequency
                }
                
                // Add the beauty (max frequency - min frequency) of the current substring to the result
                ans += maxfreq - leastfreq;
            }
        }

        return ans; // Return the total beauty sum of all substrings
    }
};
