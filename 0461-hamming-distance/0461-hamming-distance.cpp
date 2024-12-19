class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans = x ^ y;
        int count = 0;
        for (int i = 0; i < 31; i++) {
            if (ans & (1 << i)) {
                count++;
            }
        }
        return count;
    }
};