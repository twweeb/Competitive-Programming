const val mod = 1_000_000_007.toLong()

class Num(var p: Long, var q: Long) {
    init {
        p %= mod
        q %= mod
    }

    companion object {
        var c = 0L
    }

    constructor(p: Long, q: Long, irr: Long) : this(p, q) {
        c = irr
        for (i in 3L..c step 2L) {
            val j = i * i
            if (j > c) break
            while (c % j == 0L) {
                c /= j
                this.q *= i
                this.q %= mod
            }
        }
    }

    operator fun plus(other: Num) = Num(p + other.p, q + other.q)
    operator fun times(other: Num) =
        Num(
            p * other.p % mod + c % mod * q % mod * other.q % mod,
            p * other.q % mod + q * other.p % mod
        )

    override fun toString() = if (q == 0L) "$p 0 1\n" else "$p $q $c\n"
}

class Matrix(val a: Num, val c: Num) {
    operator fun times(other: Matrix) = Matrix(a * other.a,c * other.a + other.c)

    companion object {
        val b = Num(0,0)
        val d = Num(1,0)
    }

    fun pow(x: Long): Matrix =
        when {
            x == 0L -> Matrix(Num(1, 0), Num(0, 0))
            x == 1L -> this
            x % 2L == 0L -> pow(x / 2).let { it * it }
            else -> pow(x / 2).let { this * it * it }
        }
}

fun main() {
    val buf = StringBuilder()
    for (i in 1..(readLine()!!.toInt())) {
        val (a, b, n) = readLine()!!.split(" ").map { it.toLong() }
        val r = Num(a + b, 1L, 1 + b * b)
        val p = Matrix(r, Num(1,0)).pow(n)
        val area = Matrix(r * r, Num(1, 0)).pow(n)
        buf.append(p.c * r)
        buf.append(area.c * Num(b, 0))
    }
    print(buf)
}
