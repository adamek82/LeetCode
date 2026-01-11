class Subsets_78 {
    fun subsets(nums: IntArray): List<List<Int>> {
        val n = nums.size
        val out = ArrayList<List<Int>>(if (n < 31) 1 shl n else 0)
        val partial = ArrayList<Int>(n)

        fun dfs(i: Int) {
            if (i == n) {
                out.add(ArrayList(partial))
                return
            }
            dfs(i + 1)
            partial.add(nums[i])
            dfs(i + 1)
            partial.removeAt(partial.size - 1)
        }

        dfs(0)
        return out
    }
}
