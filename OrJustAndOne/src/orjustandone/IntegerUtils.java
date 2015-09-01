package orjustandone;

import java.util.BitSet;
import java.util.HashSet;
import java.util.Set;

public class IntegerUtils {

    private static final int SIEVE_SIZE = 10_000;
    private static final Set<Integer> sieve = getSieve(SIEVE_SIZE);

    public static boolean isEven(int n) {
        return (n & 1) == 0;
    }

    public static boolean isOdd(int n) {
        return n % 2 == 1;
    }

    public static boolean isPrime(int n) {
        if (n < 1) {
            return false;
        }

        if (n < SIEVE_SIZE) {
            return sieve.contains(n);
        }

        return isPrimeBrute(n);
    }

    public static boolean isPrimeBrute(int n) {
        if (n < 1) {
            return false;
        }

        if (n > 2 && (n & 1) == 0) {
            return false;
        }

        for (int i = 3; i * i <= n; i += 2) {
            if (n % i == 0) {
                return false;
            }
        }

        return true;
    }

    public static boolean isPrimeSlow(int n) {
        if (n < 1) {
            return false;
        }
        return !new String(new char[n]).matches(".?|(..+?)\\1+");
    }

    private static Set<Integer> getSieve(int size) {
        Set<Integer> primes = new HashSet<Integer>();
        BitSet nonPrimes = new BitSet(size + 1);
        for (int p = 2; p <= size; p = nonPrimes.nextClearBit(p + 1)) {
            for (int i = p * p; i <= size; i += p) {
                nonPrimes.set(i);
            }
            primes.add(p);
        }

        return primes;
    }

}
