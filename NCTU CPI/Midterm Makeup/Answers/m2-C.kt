class Matrix(var a: Long, var b: Long, var c: Long,
             var d: Long, var e: Long, var f: Long,
             var g: Long, var h: Long, var i: Long) {
    operator fun times(o: Matrix) = Matrix( (a*o.a + b*o.d + c*o.g) % mod, 
        (a*o.b + b*o.e + c*o.h) % mod, (a*o.c + b*o.f + c*o.i) % mod,
        (d*o.a + e*o.d + f*o.g) % mod, (d*o.b + e*o.e + f*o.h) % mod, 
        (d*o.c + e*o.f + f*o.i) % mod, (g*o.a + h*o.d + i*o.g) % mod, 
        (g*o.b + h*o.e + i*o.h) % mod, (g*o.c + h*o.f + i*o.i) % mod)

    companion object {
        var mod = 0L
    }

    fun pow(x: Long): Matrix = when {
            x == 0L -> Matrix(1L, 0L, 0L, 0L, 1L, 0L, 0L, 0L, 1L)
            x % 2L == 0L -> pow(x / 2).let { it * it }
            else -> pow(x / 2).let { this * it * it }
        }
}

fun main() {
    for (i in 1..(readLine()!!.toInt())) {
        val (b, n, m) = readLine()!!.split(" ").map { it.toLong() }
        Matrix.mod = m
        val matrix = Matrix(b, 0L, 0L, b, b, 0L, 0L, 1L, 1L).pow(n)
        println(b * (matrix.g + matrix.h) % m)
    }
}
