import java.util.TreeSet

fun main() {
    val (n, q) = readLine()!!.split(" ").map{ it.toInt() }
    val a = readLine()!!.split(" ").map{ it.toInt() }.toMutableList()
    val map = HashMap<Int, TreeSet<Int>>()
    val label = HashMap<Int,Int>()
    val buf = StringBuilder()
    for ((i, v) in a.withIndex()) {
        map.getOrPut(v){ TreeSet<Int>() }.add(i + 1)
        label[v] = v
    }
    for (rnd in 1..q) {
        val (cmd, x, p) = readLine()!!.split(" ").map{ it.toInt() }
        when (cmd) {
            1 -> {
                map[a[x - 1]]?.remove(x)
                a[x - 1] = label.getOrPut(p){ p }
                map.getOrPut(a[x - 1]){ TreeSet<Int>() }.add(x)
            }
            2 -> {
                var lx = label.getOrPut(x){ x }
                var lp = label.getOrPut(p){ p }
                var mx = map.getOrPut(lx){ TreeSet<Int>() }
                var mp = map.getOrPut(lp){ TreeSet<Int>() }
                if (mx.size > mp.size) {
                    label[x] = label[p]!!.also{ label[p] = label[x]!! }
                    lx = lp.also{ lp = lx }
                    mx = mp.also{ mp = mx }
                }
                for (v in mx) a[v - 1] = lp
                mp.addAll(mx)
                mx.clear()
            }
            else -> {
                val lp = label[p]
                if (lp != null) {
                    val lower = map[lp]?.floor(x) ?: -n
                    val higher = map[lp]?.ceiling(x) ?: n + n
                    val ans = minOf(x - lower, higher - x)
                    buf.append(if (ans >= n) "-1\n" else "$ans\n")
                } else {
                    buf.append("-1\n")
                }
            }
        }
    }
    print(buf)
}
