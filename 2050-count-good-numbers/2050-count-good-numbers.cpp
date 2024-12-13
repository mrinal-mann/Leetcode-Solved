#define mod 1000000007
class Solution {
public:
    long long power(long long x,long long y){
        if(y==0) return 1;
        long long ans=power(x,y/2); //recursion
        ans*=ans;
        ans%=mod;
        if(y%2) ans*=x; // multiply when y is odd
        ans%=mod;
        return ans; 
    }


    int countGoodNumbers(long long n) {
        long long even=(n%2)+(n/2); //for finding the even number of index
        long long odd=n/2; //for finding the odd number of index
        return (power(5,even)*power(4,odd))%mod; //created own power function
    }
};