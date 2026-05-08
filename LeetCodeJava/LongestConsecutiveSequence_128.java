import java.util.HashSet;
import java.util.Set;

public class LongestConsecutiveSequence_128 {
    public int longestConsecutive(int[] nums) {
        Set<Integer> set = new HashSet<>();

        for (int x : nums) {
            set.add(x);
        }

        int longest = 0;

        for (int x : set) {
            if (x != Integer.MIN_VALUE && set.contains(x - 1)) {
                continue;
            }

            int end = x;
            while (end != Integer.MAX_VALUE && set.contains(end + 1)) {
                end++;
            }

            longest = Math.max(longest, end - x + 1);
        }

        return longest;
    }
}
