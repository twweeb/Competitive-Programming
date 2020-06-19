fun Long.modulo(m: Long) = if (this < 0L) this % m + m else this % m

fun lowestFit(x: Long, a: Long, b: Long) = x + (a % b - x % b).modulo(b)

fun valid(a: List<Long>, b: List<Long>, m: Long, cap: Long): Boolean {
    val n = a.size

    var lowest = 0L
    val pred: (Int) -> Boolean = { i -> 
        lowest = maxOf(a[i] - b[i] * cap, lowestFit(lowest + 1, a[i], b[i]))
        lowest > m || lowest > a[i] + cap * b[i]
    }

    lowest = maxOf(a[0] % b[0], a[0] - b[0] * cap)
    val forwardRun = ((1 until n).firstOrNull(pred) ?: n) - 1

    lowest = maxOf(a[n-1] % b[n-1], a[n-1] - b[n-1] * cap)
    val backwardRun = ((n-2 downTo 0).firstOrNull(pred) ?: -1) + 1

    return forwardRun > 0 && forwardRun >= backwardRun && backwardRun < n-1
}

fun solve(a: List<Long>, b: List<Long>, m: Long): Long {
    if (!valid(a, b, m, 1L shl 30)) return -1L
    if (valid(a, b, m, 0L)) return 0L
    var step = 1L shl 29
    var ans = 0L
    while (step > 0L) {
        if (!valid(a, b, m, ans + step)) ans += step
        step /= 2
    }
    return ans + 1
}

fun main() {
    val (_, m) = readLine()!!.split(" ").map{ it.toLong() }
    val a = readLine()!!.split(" ").map{ it.toLong() }
    val b = readLine()!!.split(" ").map{ it.toLong() }
    println(solve(a, b, m))
}
