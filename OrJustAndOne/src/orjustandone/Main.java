package orjustandone;

public class Main {

    public static void main(String[] argv) {
        StringBuilder sb;
        sb = new StringBuilder("Even numbers: ");
        for (int i = 0; i <= 50; i++) {
            if (IntegerUtils.isEven(i)) {
                sb.append(i + ", ");
            }
        }
        sb.setLength(sb.length() - 2);
        System.out.println(sb.toString());

        sb = new StringBuilder("Odd numbers: ");
        for (int i = 0; i <= 50; i++) {
            if (IntegerUtils.isOdd(i)) {
                sb.append(i + ", ");
            }
        }
        sb.setLength(sb.length() - 2);
        System.out.println(sb.toString());

        sb = new StringBuilder("Prime numbers: ");
        for (int i = 1; i < 1000; i++) {
            if (IntegerUtils.isPrime(i)) {
                sb.append(i + ", ");
            }
        }
        sb.setLength(sb.length() - 2);
        System.out.println(sb.toString());

        sb = new StringBuilder("Slow primes:   ");
        for (int i = 1; i < 1000; i++) {
            if (IntegerUtils.isPrimeSlow(i)) {
                sb.append(i + ", ");
            }
        }
        sb.setLength(sb.length() - 2);
        System.out.println(sb.toString());
    }

}
