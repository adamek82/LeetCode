import java.util.List;
import java.util.Objects;
import java.util.function.BiPredicate;
import java.util.function.Function;

public final class TestUtils {
    private TestUtils() {}

    public static final class TestFailure extends RuntimeException {
        public TestFailure(String msg) { super(msg); }
    }

    public static void assertTrue(boolean cond, String msg) {
        if (!cond) throw new TestFailure(msg);
    }

    public static <T> void assertEquals(T expected, T got, String context) {
        if (!Objects.equals(expected, got)) {
            throw new TestFailure(context + " Expected: " + expected + ", Got: " + got);
        }
    }

    public static void assertIntArrayEquals(int[] expected, int[] got, String context) {
        if (expected == null && got == null) return;
        if (expected == null || got == null) {
            throw new TestFailure(context + " Expected: " + fmt(expected) + ", Got: " + fmt(got));
        }
        if (expected.length != got.length) {
            throw new TestFailure(context + " Expected: " + fmt(expected) + ", Got: " + fmt(got));
        }
        for (int i = 0; i < expected.length; i++) {
            if (expected[i] != got[i]) {
                throw new TestFailure(context + " Expected: " + fmt(expected) + ", Got: " + fmt(got));
            }
        }
    }

    public static <TC, R> void runCases(
        String suiteName,
        List<TC> cases,
        Function<TC, R> actual,
        Function<TC, R> expected
    ) {
        runCases(suiteName, cases, actual, expected, Objects::equals, Objects::toString);
    }

    public static <TC, R> void runCases(
        String suiteName,
        List<TC> cases,
        Function<TC, R> actual,
        Function<TC, R> expected,
        BiPredicate<R, R> eq,
        Function<R, String> fmt
    ) {
        System.out.println("Running " + suiteName + " tests:");
        int pass = 0;

        for (int i = 0; i < cases.size(); i++) {
            TC tc = cases.get(i);
            try {
                R got = actual.apply(tc);
                R exp = expected.apply(tc);
                boolean ok = eq.test(got, exp);
                System.out.println("  Test " + (i + 1) + ": res = " + (ok ? "PASS" : "FAIL") +
                    " (Expected: " + fmt.apply(exp) + ", Got: " + fmt.apply(got) + ")");
                if (ok) pass++;
            } catch (TestFailure tf) {
                System.out.println("  Test " + (i + 1) + ": res = FAIL (" + tf.getMessage() + ")");
            } catch (Exception e) {
                System.out.println("  Test " + (i + 1) + ": res = ERROR (" + e + ")");
            }
        }

        System.out.println("  => " + pass + "/" + cases.size() + " PASS");
        System.out.println();
    }

    public static String fmt(int[] a) {
        if (a == null) return "null";
        StringBuilder sb = new StringBuilder();
        sb.append("[");
        for (int i = 0; i < a.length; i++) {
            if (i > 0) sb.append(", ");
            sb.append(a[i]);
        }
        sb.append("]");
        return sb.toString();
    }
}
