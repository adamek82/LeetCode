import java.util.*;

public class LongestIncreasingSubsequence_300 {
    public int lengthOfLIS_customLowerBound(int[] nums) {
        // List to store the smallest ending elements of increasing subsequences
        ArrayList<Integer> sub = new ArrayList<>();

        for (int num : nums) {
            // Find the index where 'num' can replace an element or be inserted
            int pos = lowerBound(sub, num);
            if (pos < sub.size()) {
                // Replace the element at index 'pos' with 'num'
                sub.set(pos, num);
            } else {
                // Append 'num' to the list
                sub.add(num);
            }
        }

        // The size of the list represents the length of the LIS
        return sub.size();
    }

    public int lengthOfLIS_arraysBinarySearch(int[] nums) {
        /*
         * Java's Arrays.binarySearch(array, from, to, key) returns:
         * - the index of a matching element if the key is found,
         * - otherwise: -(insertionPoint) - 1
         *
         * The insertion point is the index where the key should be inserted
         * to keep the searched range sorted.
         *
         * For this LIS algorithm, after decoding a negative result:
         *     pos = -pos - 1;
         * 'pos' becomes the place where the current value should replace
         * an existing tail or extend the tails array.
         *
         * Note: unlike C++ lower_bound, binarySearch does not guarantee
         * returning the first equal element when duplicates exist.
         * That is still fine here, because replacing any equal tail value
         * preserves correctness of the algorithm.
         */
        int[] tails = new int[nums.length];
        int size = 0;

        for (int num : nums) {
            int pos = Arrays.binarySearch(tails, 0, size, num);
            if (pos < 0) {
                pos = -pos - 1;
            }

            tails[pos] = num;
            if (pos == size) {
                size++;
            }
        }

        return size;
    }

    // Returns the first index i such that list.get(i) >= target.
    // This is the classic lower_bound behavior from C++.
    private int lowerBound(ArrayList<Integer> list, int target) {
        int left = 0;
        int right = list.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (list.get(mid) < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return left;
    }
}
