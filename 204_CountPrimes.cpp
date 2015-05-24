/*
Description:

Count the number of prime numbers less than a non-negative number, n.
*/

//Solution 1: TLE
class Solution {
public:
    bool isPrime(int num)
    {
        int cnt = sqrt(num);
        for(int i=2;i<=cnt;++i){
            if(num%i==0)
                return false;
        }
        
        return true;
    }

    int countPrimes(int n) {
        int res = 0;
        
        if(n <=1 )
            return res;
        
        ++res;
        for(int i=3;i<=n;i+=2){
            if(isPrime(i))
                ++res;
        }
        
        return res;
    }
};

//Solution 2：筛法
class Solution {
public:
  
    int countPrimes(int n) {
        int res = 0;
        
        if(n <=1 )
            return res;
        
        vector<bool> isprime(n,true);
        int cnt = sqrt(n);
        for(int i=2;i<=cnt;++i){
            if(isprime[i]){
                for(int j=i;i*j<=n;++j)
                    isprime[i*j] = false;
            }
        }
        
        for(int i=2;i<n;++i){
            if(isprime[i])
                ++res;
        }
        
        return res;
    }
};