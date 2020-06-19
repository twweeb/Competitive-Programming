fun valid(a: List<Long>, b: List<Long>, m: Long, cap: Long): Boolean {
    val n = a.size
    var forwardRun = n-1
    var backwardRun = 0

    var lowest = maxOf(a[0] % b[0], a[0] - b[0] * cap)
    for (i in 1 until n) {
        lowest = maxOf(a[i] - b[i] * cap,  (lowest + 1).let{
            it + ((a[i] % b[i]) - (it % b[i])).let{
                if (it < 0) it + b[i] else it
            }
        })
        if (lowest > m || lowest > a[i] + cap * b[i]) {
            forwardRun = i - 1
            break
        }
    }

    lowest = maxOf(a[n-1] % b[n-1], a[n-1] - b[n-1] * cap)
    for (i in n-2 downTo 0) {
        lowest = maxOf(a[i] - b[i] * cap,  (lowest + 1).let{
            it + ((a[i] % b[i]) - (it % b[i])).let{
                if (it < 0) it + b[i] else it
            }
        })
        if (lowest > m || lowest > a[i] + cap * b[i]) {
            backwardRun = i + 1
            break
        }
    }

    return forwardRun > 0 && forwardRun >= backwardRun && backwardRun < n-1
}

fun solve(a: List<Long>, b: List<Long>, m: Long): Long {
    if (!valid(a, b, m, 1L shl 30)) return -1L
    if (valid(a, b, m, 0L)) return 0L
    var step = 1L shl 29
    var ans = 0L
    while (step > 0L) {
        if (!valid(a, b, m, ans + step))
            ans += step
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
