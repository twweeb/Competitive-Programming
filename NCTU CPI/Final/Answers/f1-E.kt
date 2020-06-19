class Matrix(val a: Long, val b: Long, val c: Long, val d: Long) {
    operator fun times(o: Matrix) = Matrix(
        (a*o.a+b*o.c) % 1_000_000_007, (a*o.b+b*o.d) % 1_000_000_007,
        (c*o.a+d*o.c) % 1_000_000_007, (c*o.b+d*o.d) % 1_000_000_007)
    fun pow(x: Long): Matrix = when {
        x == 0L -> Matrix(1L,0L,0L,1L)
        x == 1L -> this
        x % 2 == 0L -> pow(x/2).let{ it * it }
        else -> this * pow(x/2).let{ it * it }
    }
}

fun f(n: Long): Long {
    if (n <= 2L) return n * n
    val m = Matrix(0,1,4,2).pow(n-2)
    return (m.c + m.d*4) % 1_000_000_007
}

fun main() = println(f(readLine()!!.toLong()))
