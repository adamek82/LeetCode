public final class GridUtils {
    private GridUtils() {}

    public static int[][] copy(int[][] a) {
        if (a == null) return null;
        int[][] r = new int[a.length][];
        for (int i = 0; i < a.length; i++) {
            r[i] = (a[i] == null) ? null : a[i].clone();
        }
        return r;
    }

    public static char[][] copy(char[][] a) {
        if (a == null) return null;
        char[][] r = new char[a.length][];
        for (int i = 0; i < a.length; i++) {
            r[i] = (a[i] == null) ? null : a[i].clone();
        }
        return r;
    }

    public static int[][] deepCopyPoints(int[][] points) {
        return copy(points);
    }
}
