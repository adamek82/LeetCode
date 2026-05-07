public class TrappingRainWater_42 {
    public int trap(int[] height) {
        int n = height.length;
        if (n < 3) return 0;

        int l = 0, r = n - 1;
        int leftMax = 0, rightMax = 0;
        int water = 0;

        while (l < r) {
            if (height[l] <= height[r]) {
                leftMax = Math.max(leftMax, height[l]);
                water += leftMax - height[l];
                l++;
            } else {
                rightMax = Math.max(rightMax, height[r]);
                water += rightMax - height[r];
                r--;
            }
        }

        return water;
    }
}
