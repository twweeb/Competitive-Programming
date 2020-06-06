fun solve() {
    val toks = readLine()!!.split(" ")
    var n = toks[0].toInt()
    var remains = toks[1].toLong() - 1L
    var a = 0
    var b = 0
    for (i in 2 until n) {
        val cnt = i * (i - 1) / 2
        if (remains < cnt) {
            a = i
            break
        }
        remains -= cnt
    }
    for (i in 1 until a) {
        if (remains < i) {
            b = i
            break
        }
        remains -= i
    }
    println("${n-a} ${n-b} ${n-remains}")
}

fun main() = (1..readLine()!!.toInt()).forEach{ solve() }
