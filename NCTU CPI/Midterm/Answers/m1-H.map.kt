import java.util.TreeMap

fun main() {
    val seq = TreeMap<Long, Int>().apply {
        put(0L, 0)
        put(1_000_000_000_001L, 1_000_000_001)
    }
    val buf = StringBuilder()
    (1..readLine()!!.toInt()).forEach {
        val toks = readLine()!!.split(" ")
        if (toks[0] == "1") {
            val x = toks[1].toLong()
            val y = toks[2].toInt()
            val lower = seq.lowerEntry(x)!!
            if (lower.value < y) {
                var higher = seq.higherEntry(x)!!
                while (higher.value <= y) {
                    seq -= higher.key
                    higher = seq.higherEntry(x)!!
                }
                seq[x] = y
            }
        } else {
            buf.append("${seq.floorEntry(toks[1].toLong())?.value}\n")
        }
    }
    print(buf)
}
