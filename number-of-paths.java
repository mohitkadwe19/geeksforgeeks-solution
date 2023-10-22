class Solution{
    static final long MOD = 1000000007;

    public int numberOfPaths(int M, int N) {
        int totalSteps = M + N - 2;
        int downSteps = M - 1;

        long num = 1;
        long den = 1;

        for (int i = 1; i <= downSteps; i++) {
            num = (num * (totalSteps - i + 1)) % MOD;
            den = (den * i) % MOD;
        }

        long inverseDen = modularInverse(den, MOD);

        long result = (num * inverseDen) % MOD;

        return (int) result;
    }

    private long modularInverse(long a, long m) {
        // Calculate a^(-1) mod m using Fermat's Little Theorem.
        // Assumes m is a prime number.
        return binExp(a, m - 2, m);
    }

    private long binExp(long base, long power, long mod) {
        long result = 1;
        base %= mod;
        while (power > 0) {
            if (power % 2 == 1) {
                result = (result * base) % mod;
            }
            power >>= 1;
            base = (base * base) % mod;
        }
        return result;
    }

}