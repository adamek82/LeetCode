import kotlin.math.abs

object TestUtils {
    fun IntArray.pretty(): String =
        joinToString(prefix = "[", postfix = "]")

    fun DoubleArray.pretty(): String =
        joinToString(prefix = "[", postfix = "]")

    fun Array<IntArray>.pretty(): String =
        contentDeepToString()

    fun <T> assertEq(label: String, expected: T, got: T): Boolean {
        val pass = expected == got
        println(
            "$label: ${if (pass) "PASS" else "FAIL"}" +
                if (pass) "" else " (Expected: $expected, Got: $got)"
        )
        return pass
    }

    fun assertApprox(
        label: String,
        expected: Double,
        got: Double,
        eps: Double = 1e-5
    ): Boolean {
        val pass = abs(expected - got) <= eps
        println(
            "$label: ${if (pass) "PASS" else "FAIL"}" +
                if (pass) "" else " (Expected: $expected, Got: $got, eps: $eps)"
        )
        return pass
    }

    fun assertIntArrayEq(label: String, expected: IntArray, got: IntArray): Boolean {
        val pass = expected.contentEquals(got)
        println(
            "$label: ${if (pass) "PASS" else "FAIL"}" +
                if (pass) "" else " (Expected: ${expected.pretty()}, Got: ${got.pretty()})"
        )
        return pass
    }

    fun assertDoubleArrayApproxEq(
        label: String,
        expected: DoubleArray,
        got: DoubleArray,
        eps: Double = 1e-5
    ): Boolean {
        val pass = expected.size == got.size &&
            expected.indices.all { abs(expected[it] - got[it]) <= eps }

        println(
            "$label: ${if (pass) "PASS" else "FAIL"}" +
                if (pass) "" else
                    " (Expected: ${expected.pretty()}, Got: ${got.pretty()}, eps: $eps)"
        )
        return pass
    }

    fun assertMatrixEq(
        label: String,
        expected: Array<IntArray>,
        got: Array<IntArray>
    ): Boolean {
        val pass = expected.contentDeepEquals(got)
        println(
            "$label: ${if (pass) "PASS" else "FAIL"}" +
                if (pass) "" else " (Expected: ${expected.pretty()}, Got: ${got.pretty()})"
        )
        return pass
    }

    fun <T> prettyNestedLists(
        value: List<List<T>>,
        elementFormatter: (T) -> String = { it.toString() }
    ): String =
        value.joinToString(prefix = "[", postfix = "]") { inner ->
            inner.joinToString(prefix = "[", postfix = "]") { elementFormatter(it) }
        }

    fun <T : Comparable<T>> normalizeListsSizeThenLex(value: List<List<T>>): List<List<T>> =
        value
            .map { it.sorted() }
            .sortedWith { a, b ->
                if (a.size != b.size) {
                    a.size.compareTo(b.size)
                } else {
                    var cmp = 0
                    for (i in a.indices) {
                        cmp = a[i].compareTo(b[i])
                        if (cmp != 0) break
                    }
                    cmp
                }
            }

    fun <T : Comparable<T>> assertListsAnyOrder(
        label: String,
        expected: List<List<T>>,
        got: List<List<T>>,
        formatter: (List<List<T>>) -> String = { it.toString() }
    ): Boolean {
        val normalizedExpected = normalizeListsSizeThenLex(expected)
        val normalizedGot = normalizeListsSizeThenLex(got)
        val pass = normalizedExpected == normalizedGot

        println(
            "$label: ${if (pass) "PASS" else "FAIL"}" +
                if (pass) "" else
                    " (Expected: ${formatter(normalizedExpected)}, Got: ${formatter(normalizedGot)})"
        )
        return pass
    }
}
