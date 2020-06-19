data class Hydra(val head: Int, val tail: Int)

fun main() {
    val (h, t) = readLine()!!.split(" ").map{ it.toInt() }
    val queue = java.util.ArrayDeque<Hydra>().apply{ addLast(Hydra(0,0)) }
    val depth = HashMap<Hydra,Int>().apply{ this[Hydra(0,0)] = 0 }
    while(true) {
        val first = queue.removeFirst()
        if (first.head == h && first.tail == t) return println(depth[first])
        val (fh, ft) = first
        listOf(Hydra(fh+3,ft),Hydra(fh-2,ft+3),Hydra(fh+2,ft-1),Hydra(fh,ft-2))
            .filter{ it !in depth && it.head >= 0 && it.tail >= 0 }
            .forEach{
                depth[it] = depth[first]!! + 1
                queue.addLast(it)
            }
    }
}
