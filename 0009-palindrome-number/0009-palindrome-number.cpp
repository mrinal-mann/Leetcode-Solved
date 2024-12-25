class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        long long num = x;
        long long ans = 0;
        while(x){
            int digit = x%10;
            ans = ans*10 + digit;
            x /= 10; 
        }
        return ans == num; //return
    }
};