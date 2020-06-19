fun solve() {
    val (a, b, c, d) = readLine()!!.split(" ").map{it.toLong()}
    val side = listOf( maxOf(a+c, maxOf(b,d)), maxOf(a+d, maxOf(b,c)), 
                       maxOf(b+c, maxOf(a,d)), maxOf(b+d, maxOf(a,c))).min()!!
    println(side*side)
}

fun main() = (1..readLine()!!.toInt()).forEach{ solve() }
