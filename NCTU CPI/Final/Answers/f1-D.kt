class BIT(val n: Int) {
    val arr = LongArray(n+1){0L}
    fun query(pos: Int): Long {
        var ret = 0L
        var x = pos
        while (x > 0) {
            ret += arr[x]
            x -= x and -x
        }
        return ret
    }
    fun update(pos: Int, d: Long) {
        var x = pos
        while (x <= n) {
            arr[x] += d
            x += x and -x
        }
    }
}

fun main() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(" ").map{ it.toInt() }
    val ans = LongArray(n){0L}
    val m = 200_000
    val forward = BIT(m)
    val backward = BIT(m)
    a.asSequence().drop(1).forEach{ backward.update(it, 1L) }

    forward.update(a[0],1L)
    for (i in 1 until n-1) {
        backward.update(a[i],-1L)
        ans[i] += forward.query(a[i]-1) * backward.query(a[i]-1)
        forward.update(a[i],1L)
    }

    val fCnt = BIT(m)
    val fAcc = BIT(m)
    fCnt.update(a[0], 1)
    for (i in 1 until n) {
        ans[i] += fAcc.query(m) - fAcc.query(a[i])
        fAcc.update(a[i], fCnt.query(a[i]-1))
        fCnt.update(a[i], 1)
    }

    val bCnt = BIT(m)
    val bAcc = BIT(m)
    bCnt.update(a[n-1], 1)
    for (i in (n-2) downTo 0) {
        ans[i] += bAcc.query(m) - bAcc.query(a[i])
        bAcc.update(a[i], bCnt.query(a[i]-1))
        bCnt.update(a[i], 1)
    }

    println(ans.joinToString(" "))
}
