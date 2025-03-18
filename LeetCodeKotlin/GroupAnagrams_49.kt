class GroupAnagrams_49 {
    fun groupAnagrams_sorting(strs: Array<String>): List<List<String>> {
        val anagramGroups = mutableMapOf<String, MutableList<String>>()

        for (s in strs) {
            val sortedStr = s.toCharArray().sorted().joinToString("")
            anagramGroups.getOrPut(sortedStr) { mutableListOf() }.add(s)
        }

        return anagramGroups.values.toList()
    }

    fun groupAnagrams_counting(strs: Array<String>): List<List<String>> {
        val anagramGroups = mutableMapOf<String, MutableList<String>>()

        for (s in strs) {
            val key = CharArray(26) { '0' }  // Initialize key with '0's
            for (c in s) key[c - 'a']++  // Increment corresponding position

            val keyStr = String(key)  // Convert CharArray to a string
            anagramGroups.getOrPut(keyStr) { mutableListOf() }.add(s)
        }

        return anagramGroups.values.toList()
    }
}