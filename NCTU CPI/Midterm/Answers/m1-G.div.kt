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
    fun inv(): Num {
        val mag = Num( p * p % mod - c * q % mod * q % mod + mod, 0L)
        return mag.pow(mod-2) * Num(p,mod-q)
    }
    operator fun div(other: Num) = this * other.inv()

    fun pow(x: Long): Num = when {
        x == 0L -> Num(1L, 0L)
        x == 1L -> this
        x % 2L == 0L -> pow(x / 2).let { it * it }
        else -> pow(x / 2).let { this * it * it }
    }

    override fun toString() = if (q == 0L) "$p 0 1\n" else "$p $q $c\n"
}

fun main() {
    val buf = StringBuilder()
    for (i in 1..(readLine()!!.toInt())) {
        val (a, b, n) = readLine()!!.split(" ").map { it.toLong() }
        val r = Num(a + b, 1L, 1 + b * b)
        val minusOne = Num(mod - 1L, 0L)
        buf.append(r * (r.pow(n) + minusOne) / (r + minusOne))
        buf.append(Num(b, 0) * (r.pow(2 * n) + minusOne) / (r * r + minusOne))
    }
    print(buf)
}