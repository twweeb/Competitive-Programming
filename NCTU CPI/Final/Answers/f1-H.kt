fun main() {
    val (p, n) = readLine()!!.split(" ").map{ it.toInt() }
    val best = IntArray(p+1){0}
    for (i in 1..n) {
        val (pool, box) = readLine()!!.split(" ").map{ it.toInt() }
        best[pool] = best.asSequence().take(pool+1).max()!! + box
    }
    println(best.max()!!)
}
