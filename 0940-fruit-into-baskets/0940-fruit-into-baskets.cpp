class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size(); // Correctly use the parameter name
        unordered_map<int, int> umap; // Stores the frequency of fruits
        int maxFruitCount = 0;
        int low = 0; // Left pointer of the sliding window

        for (int high = 0; high < n; ++high) {
            umap[fruits[high]]++; // Add the current fruit to the basket

            // Shrink the window if there are more than 2 types of fruits
            while (umap.size() > 2) {
                umap[fruits[low]]--; // Remove one fruit of type fruits[low]
                if (umap[fruits[low]] == 0) {
                    umap.erase(fruits[low]); // Remove the fruit type if count becomes 0
                }
                low++; // Move the left pointer
            }

            // Update the maximum fruit count
            maxFruitCount = max(maxFruitCount, high - low + 1);
        }

        return maxFruitCount;
    }
};
