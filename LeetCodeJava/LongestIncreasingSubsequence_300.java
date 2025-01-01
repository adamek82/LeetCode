import java.util.*;

public class LongestIncreasingSubsequence_300 {
    public int lengthOfLIS(int[] nums) {
        // List to store the smallest ending elements of increasing subsequences
        ArrayList<Integer> sub = new ArrayList<>();

        for (int num : nums) {
            // Find the index where 'num' can replace an element or be inserted
            int pos = binarySearch(sub, num);
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

    // Custom binary search to find the index where 'target' fits
    private int binarySearch(ArrayList<Integer> list, int target) {
        int left = 0, right = list.size() - 1;
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
